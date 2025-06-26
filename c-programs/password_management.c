#include <stdio.h>
#include <string.h>

#define FILE_NAME "passwords.txt"

int main() {
    int choice;

    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

int checkPassword(char password[100]) {
    int i, length = strlen(password), Up, Low, Dig, Sp;

    if (length < 8) {
        printf("Error: Password must be at least 8 characters long.\n");
        return 0;
    }

    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z')
            Up = 1;
        if (password[i] >= 'a' && password[i] <= 'z')
            Low = 1;
        if (password[i] >= '0' && password[i] <= '9')
            Dig = 1;
        if (strchr("@#$%^&*!", password[i]))
            Sp = 1;
    }

    if (!Up || !Low || !Dig || !Sp) {
        printf("Error: Password must include uppercase, lowercase, number, and special character.\n");
        return 0;
    }

    return 1;
}

void encrypt(char password[100]) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if ((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z'))
            password[i] += 3;
        else if (password[i] >= '0' && password[i] <= '9')
            password[i] = ((password[i] - '0' + 3) % 10) + '0';
    }
}

void savePassword(char password[100]) {
    FILE *file = fopen(FILE_NAME, "w");
        fprintf(file, "%s", password);
        fclose(file);
        printf("Password saved successfully!\n");

}

int getPassword(char password[100]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        fgets(password, 100, file);
        fclose(file);
        return 1;
    }
    printf("No password found! Register first.\n");
    return 0;
}

void registerUser() {
    char password[100];
    do {
        printf("Set a password: ");
        scanf("%s", password);
    } while (!checkPassword(password));

    encrypt(password);
    savePassword(password);
}

void loginUser() {
    char password[100], stored[100];
    int a = 3;

    if (!getPassword(stored)) return;

    while (a > 0) {
        printf("Enter password: ");
        scanf("%s", password);

        encrypt(password);

        if (strcmp(password, stored) == 0) {
            printf("Access Granted!\n");
            return;
        }

        a--;
        printf("Access Denied! Attempts left: %d\n", a);
    }

    printf("Too many failed attempts! Access locked temporarily.\n");
}
