#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    int carNumber;
    char ownerName[50];
    struct Car* next;
};

struct Car* head = NULL; // Global head pointer for the linked list

typedef void (*CarFunction)();

void parkCar();
void removeCar();
void displayCars();
void searchCarByNumber();
void searchCarByOwner();
void calculateExpectedTime();
void addCarToWaitingList();
void manageParking();
void makePayment();
void trackLocation();

void executeFunction(CarFunction function) {
    function();
}

void parkCar() {
    int carNumber;
    char ownerName[50];

    printf("Enter the car number: ");
    scanf("%d", &carNumber);

    printf("Enter the owner's name: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(ownerName, sizeof(ownerName), stdin);
    ownerName[strcspn(ownerName, "\n")] = '\0'; // Remove the newline character

    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    newCar->carNumber = carNumber;
    strncpy(newCar->ownerName, ownerName, sizeof(newCar->ownerName));
    newCar->next = NULL;

    if (head == NULL) {
        head = newCar;
    } else {
        struct Car* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
    }

    printf("Car number %d parked successfully.\n", carNumber);
}

void removeCar() {
    int carNumber;

    printf("Enter the car number: ");
    scanf("%d", &carNumber);

    if (head == NULL) {
        printf("Car park is empty.\n");
        return;
    }

    struct Car* current = head;
    struct Car* previous = NULL;

    while (current != NULL && current->carNumber != carNumber) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Car number %d is not parked.\n", carNumber);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    printf("Car number %d removed successfully.\n", carNumber);
    free(current);
}

void displayCars() {
    if (head == NULL) {
        printf("Car park is empty.\n");
        return;
    }

    struct Car* current = head;
    printf("Cars parked in the car park:\n");

    while (current != NULL) {
        printf("Car number: %d, Owner: %s\n", current->carNumber, current->ownerName);
        current = current->next;
    }
}

void searchCarByNumber() {
    int carNumber;

    printf("Enter the car number: ");
    scanf("%d", &carNumber);

    struct Car* current = head;
    while (current != NULL) {
        if (current->carNumber == carNumber) {
            printf("Car number: %d, Owner: %s\n", current->carNumber, current->ownerName);
            return;
        }
        current = current->next;
    }

    printf("Car number %d is not parked.\n", carNumber);
}

void searchCarByOwner() {
    char ownerName[50];

    printf("Enter the owner's name: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(ownerName, sizeof(ownerName), stdin);
    ownerName[strcspn(ownerName, "\n")] = '\0'; // Remove the newline character

    struct Car* current = head;
    while (current != NULL) {
        if (strcmp(current->ownerName, ownerName) == 0) {
            printf("Car number: %d, Owner: %s\n", current->carNumber, current->ownerName);
            return;
        }
        current = current->next;
    }

    printf("No cars found for owner: %s\n", ownerName);
}

void calculateExpectedTime() {
    printf("Calculating expected time...\n");
    // Implementation for expected time calculation
}

void addCarToWaitingList() {
    printf("Adding car to waiting list...\n");
    // Implementation for adding car to waiting list
}

void manageParking() {
    printf("Managing parking...\n");
    // Implementation for parking management panel
}

void makePayment() {
    printf("Making payment...\n");
    // Implementation for payment method
}

void trackLocation() {
    printf("Tracking location using AI...\n");
    // Implementation for AI-based location tracking
}

int main() {
    int choice;

    CarFunction functionPointers[] = {
        parkCar, removeCar, displayCars, searchCarByNumber,
        searchCarByOwner, calculateExpectedTime, addCarToWaitingList,
        manageParking, makePayment, trackLocation
    };

    while (1) {
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. Display parked cars\n");
        printf("4. Search car by number\n");
        printf("5. Search car by owner\n");
        printf("6. Calculate expected time\n");
        printf("7. Add car to waiting list\n");
        printf("8. Manage parking\n");
        printf("9. Make payment\n");
        printf("10. Track car location\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 11) {
            printf("Exiting the program.\n");
            break;
        } else if (choice < 1 || choice > 10) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        executeFunction(functionPointers[choice - 1]);
    }

    return 0;
}
