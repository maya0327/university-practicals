#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTEMPTS 3
#define SHIFT 3
#define FILENAME "passwords.txt"

void encrypt(char *password, char *encrypted) {
    for (int i = 0; password[i] != '\0'; i++) {
        encrypted[i] = isalpha(password[i]) ? password[i] + SHIFT : password[i];
    }
    encrypted[strlen(password)] = '\0';
}

int validate_password(char *password) {
    if (strlen(password) < 8) return 0;
    int has_upper = 0, has_lower = 0, has_digit = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
    }
    return has_upper && has_lower && has_digit;
}

void store_password(char *encrypted) {
    FILE *file = fopen(FILENAME, "w");
    if (file) {
        fprintf(file, "%s\n", encrypted);
        fclose(file);
    }
}

int authenticate(char *input_password) {
    char encrypted[100];
    encrypt(input_password, encrypted);

    FILE *file = fopen(FILENAME, "r");
    if (!file) return 0;

    char stored_password[100];
    fscanf(file, "%s", stored_password);
    fclose(file);

    return strcmp(encrypted, stored_password) == 0;
}

int main() {
    char password[100];

    while (1) {
        printf("Set a strong password: ");
        scanf("%s", password);

        if (validate_password(password)) {
            char encrypted[100];
            encrypt(password, encrypted);
            store_password(encrypted);
            printf("Password set successfully.\n");
            break;
        } else {
            printf("Invalid password. Try again.\n");
        }
    }

    for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {
        printf("Enter your password to login: ");
        scanf("%s", password);

        if (authenticate(password)) {
            printf("Access Granted.\n");
            return 0;
        } else {
            printf("Access Denied. Try again.\n");
        }
    }

    printf("Too many failed attempts. Access locked temporarily.\n");
    return 1;
}
