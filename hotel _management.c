#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    int capacity;
    float price;
    int isOccupied;
    struct Room* next;
};

struct Reservation {
    int reservationNumber;
    int roomNumber;
    char guestName[100];
    struct Reservation* next;
};

struct Hotel {
    struct Room* rooms;
    struct Reservation* reservations;
};

struct Room* createRoom(int roomNumber, int capacity, float price) {
    struct Room* newRoom = (struct Room*)malloc(sizeof(struct Room));
    newRoom->roomNumber = roomNumber;
    newRoom->capacity = capacity;
    newRoom->price = price;
    newRoom->isOccupied = 0;
    newRoom->next = NULL;
    return newRoom;
}

struct Reservation* createReservation(int reservationNumber, int roomNumber, const char* guestName) {
    struct Reservation* newReservation = (struct Reservation*)malloc(sizeof(struct Reservation));
    newReservation->reservationNumber = reservationNumber;
    newReservation->roomNumber = roomNumber;
    strncpy(newReservation->guestName, guestName, sizeof(newReservation->guestName) - 1);
    newReservation->next = NULL;
    return newReservation;
}

void addRoom(struct Hotel* hotel, int roomNumber, int capacity, float price) {
    struct Room* newRoom = createRoom(roomNumber, capacity, price);
    newRoom->next = hotel->rooms;
    hotel->rooms = newRoom;
}

void addReservation(struct Hotel* hotel, int reservationNumber, int roomNumber, const char* guestName) {
    struct Reservation* newReservation = createReservation(reservationNumber, roomNumber, guestName);
    newReservation->next = hotel->reservations;
    hotel->reservations = newReservation;
}

void displayRooms(struct Hotel* hotel) {
    struct Room* currentRoom = hotel->rooms;
    printf("Room List:\n");
    while (currentRoom != NULL) {
        printf("Room %d | Capacity: %d | Price: $%.2f | %s\n", currentRoom->roomNumber, currentRoom->capacity, currentRoom->price, currentRoom->isOccupied ? "Occupied" : "Available");
        currentRoom = currentRoom->next;
    }
}

void displayReservations(struct Hotel* hotel) {
    struct Reservation* currentReservation = hotel->reservations;
    printf("Reservation List:\n");
    while (currentReservation != NULL) {
        printf("Reservation #%d | Room %d | Guest: %s\n", currentReservation->reservationNumber, currentReservation->roomNumber, currentReservation->guestName);
        currentReservation = currentReservation->next;
    }
}

int main() {
    struct Hotel hotel;
    hotel.rooms = NULL;
    hotel.reservations = NULL;

    addRoom(&hotel, 101, 2, 100.0);
    addRoom(&hotel, 102, 4, 150.0);
    addRoom(&hotel, 103, 3, 120.0);

    addReservation(&hotel, 1, 101, "John Doe");
    addReservation(&hotel, 2, 102, "Jane Smith");

    displayRooms(&hotel);
    displayReservations(&hotel);

    return 0;
}
