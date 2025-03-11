#pragma once
#include "guest.h"
#include <stdbool.h>
#define BOOKED 'X' 
#define UNBOOKED 'O'
#define PLACEHOLDER "placeholder"

//madisont - prog71985 - assign4, q2 - hotel rooms interface

//Hotel Rooms library
#ifndef ROOMS_LIBRARY_H
#define ROOMS_LIBRARY_H

typedef enum sortType { FIRSTNAME, LASTNAME } SORTTYPE;

typedef struct hotelRoom {
	int roomNumber;
	char bookStatus;		//O = available, X = unavailable
	GUEST roomGuest;
} ROOM; 

ROOM createRoom(int roomNumber, char bookStatus, GUEST g);

// Function to generate unbooked rooms
void createUnbookedRooms(ROOM r[], int);

//Function to write all rooms to a file
void writeRooms(ROOM r[], char*);

// Function to read all rooms from a file
bool readRooms(ROOM r[], char*);

//Option a) Show number of empty (unbooked) rooms
int numOfEmptyRooms(ROOM*);

//Option b) Show list of the empty (unbooked) rooms
void listEmptyRooms(ROOM*);

//Option d) Book a room to a guest
//ROOM bookRoom(int, char, GUEST);
ROOM bookRoomToGuest(ROOM r[], int numRooms, GUEST g);

void displaySortedGuests(ROOM*, SORTTYPE);

//Option e) Delete an existing room booking
void deleteBooking(ROOM*);

#endif //ROOMS_LIBRARY_H