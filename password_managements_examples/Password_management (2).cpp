
#include <stdio.h>
#include <string.h>

int main() {
    char username[20];
    char password[20];
    char storedPassword[20];

    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Store password in a file
    FILE *file = fopen("password.txt", "w");
    fprintf(file, "%s", password);
    fclose(file);

    // Retrieve stored password from file
    file = fopen("password.txt", "r");
    fscanf(file, "%s", storedPassword);
    fclose(file);

    // Check if entered password matches stored password
    if(strcmp(password, storedPassword) == 0) {
        printf("Password matched. Access granted.\n");
    } else {
        printf("Incorrect password. Access denied.\n");
    }

    return 0;
}
