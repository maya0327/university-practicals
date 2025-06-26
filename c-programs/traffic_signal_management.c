#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char location[50];
    char status[10];
    int vehicleCount;
} TrafficSignal;

int main() {
    int n, choice, id;
    printf("Enter the number of traffic signals: ");
    scanf("%d", &n);
    TrafficSignal signals[n];

    for (int i = 0; i < n; i++) {
        printf("\nSignal %d ID: ", i + 1);
        scanf("%d", &signals[i].id);
        printf("Location: ");
        scanf(" %[^\n]", signals[i].location);
        printf("Status (Green, Red, Yellow): ");
        scanf(" %[^\n]", signals[i].status);
        printf("Vehicle Count: ");
        scanf("%d", &signals[i].vehicleCount);
    }

    printf("\nTraffic Signal Management\n");
    printf("1. Display all traffic signal details\n");
    printf("2. Update the status of a traffic signal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nTraffic Signal Details:\n");
            for (int i = 0; i < n; i++) {
                printf("\nID: %d\nLocation: %s\nStatus: %s\nVehicle Count: %d\n",
                       signals[i].id, signals[i].location, signals[i].status, signals[i].vehicleCount);
            }
            break;

        case 2:
            printf("\nEnter the Signal ID to update the status: ");
            scanf("%d", &id);
            for (int i = 0; i < n; i++) {
                if (signals[i].id == id) {
                    printf("Enter the new status (Green, Red, Yellow): ");
                    scanf(" %[^\n]", signals[i].status);
                    printf("Status updated successfully.\n");
                }
            }
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            }

        }
