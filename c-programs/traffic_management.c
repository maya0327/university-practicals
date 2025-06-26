#include <stdio.h>
#include <string.h>

union Vehicle {
    int VEHICLEID;
    char vehicleType[10];
    char time[6];
};

void recordEntry(union Vehicle VEHICLEID[], union Vehicle vehicleType[], union Vehicle entryTime[], int count);
void recordExit(union Vehicle VEHICLEID[], union Vehicle entryTime[], union Vehicle exitTime[], int count);
void calculateTimeSpent(const char entryTime[], const char exitTime[]);

int main() {
    int choice, count = 0;
    union Vehicle VEHICLEID[100], vehicleType[100], entryTime[100], exitTime[100];

    do {
        printf("\nVehicle Entry and Exit Management\n");
        printf("1. RECORD VEHICLE ENTRY\n");
        printf("2. RECORD VEHICLE EXIT AND CALCULATE TIME SPENT\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordEntry(VEHICLEID, vehicleType, entryTime, count);
                count++;
                break;
            case 2:
                if (count == 0) {
                    printf("No vehicle records available. Please add an entry first.\n");
                } else {
                    recordExit(VEHICLEID, entryTime, exitTime, count);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void recordEntry(union Vehicle VEHICLEID[], union Vehicle vehicleType[], union Vehicle entryTime[], int count) {
    printf("\nEnter details for the vehicle:\n");
    printf("Vehicle ID: ");
    scanf("%d", &VEHICLEID[count].VEHICLEID);
    printf("Vehicle Type (Car, Bus, Bike): ");
    scanf(" %[^\n]", vehicleType[count].vehicleType);
    printf("Entry Time (HH:MM): ");
    scanf(" %[^\n]", entryTime[count].time);

    printf("Vehicle entry recorded successfully.\n");
}

void recordExit(union Vehicle VEHICLEID[], union Vehicle entryTime[], union Vehicle exitTime[], int count) {
    int id, found = 0;
    printf("\nEnter the Vehicle ID for exit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (VEHICLEID[i].VEHICLEID == id) {
            printf("Enter Exit Time (HH:MM): ");
            scanf(" %[^\n]", exitTime[i].time);
            printf("Exit recorded successfully.\n");

            printf("\nCalculating time spent by the vehicle...\n");
            calculateTimeSpent(entryTime[i].time, exitTime[i].time);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Vehicle with ID %d not found.\n", id);
    }
}

void calculateTimeSpent(const char entryTime[], const char exitTime[]) {
    int entryHours, entryMinutes, exitHours, exitMinutes;
    int totalEntryMinutes, totalExitMinutes, totalMinutesSpent;

    sscanf(entryTime, "%d:%d", &entryHours, &entryMinutes);
    sscanf(exitTime, "%d:%d", &exitHours, &exitMinutes);

    totalEntryMinutes = entryHours * 60 + entryMinutes;
    totalExitMinutes = exitHours * 60 + exitMinutes;

    totalMinutesSpent = totalExitMinutes - totalEntryMinutes;

    printf("Time spent by the vehicle: %d hours and %d minutes.\n",
           totalMinutesSpent / 60, totalMinutesSpent % 60);
}

