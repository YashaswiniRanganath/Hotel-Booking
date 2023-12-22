Room:

roomNumber: Unique identifier for each room.
capacity: Maximum number of guests the room can accommodate.
price: Cost per night for the room.
isOccupied: Flag indicating whether the room is occupied or available.
next: Pointer to the next room in the linked list.
Reservation:

reservationNumber: Unique identifier for each reservation.
roomNumber: Room number associated with the reservation.
guestName: Name of the guest making the reservation.
next: Pointer to the next reservation in the linked list.
Hotel:

rooms: Pointer to the linked list of rooms.
reservations: Pointer to the linked list of reservations.
Functions:
createRoom(int roomNumber, int capacity, float price)

Allocates memory for a new room and initializes its attributes.
Returns a pointer to the newly created room.
createReservation(int reservationNumber, int roomNumber, const char* guestName)

Allocates memory for a new reservation and initializes its attributes.
Returns a pointer to the newly created reservation.
addRoom(struct Hotel* hotel, int roomNumber, int capacity, float price)

Creates a new room and adds it to the linked list of rooms in the hotel.
addReservation(struct Hotel* hotel, int reservationNumber, int roomNumber, const char* guestName)

Creates a new reservation and adds it to the linked list of reservations in the hotel.
displayRooms(struct Hotel* hotel)

Displays the list of rooms in the hotel along with their details.
displayReservations(struct Hotel* hotel)

Displays the list of reservations in the hotel along with their details.
Usage:
Setting up the Hotel:

Use the addRoom function to add rooms to the hotel.
Use the addReservation function to make reservations.
Displaying Information:

Use displayRooms to view the current list of rooms.
Use displayReservations to view the current list of reservations.
