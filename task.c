#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    union {
        int flagInt;
        char flagStr[6];
    } active;
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter active flag (1/0/true/false): ");
    scanf("%s", newUser.active.flagStr);

    if (strcmp(newUser.active.flagStr, "1") == 0 || strcmp(newUser.active.flagStr, "true") == 0) {
        newUser.active.flagInt = 1;
    } else {
        newUser.active.flagInt = 0;
    }

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].active.flagInt) {
                printf("Login successful.\n");
                return;
            } else {
                printf("User is not active. Cannot login.\n");
                return;
            }
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}