#define _CRT_SECURE_NO_WARNINGS
#include "rooms.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//madisont - prog71985 - assign4, q2 - implementation

//The program uses an array of 10 structures. Each structure should hold
//a room identification number, a marker that indicates whether the room
//is booked, and the first and last names of the booking guest

//Create Room function
ROOM createRoom(int number, char status, GUEST guest) {
	ROOM room;
	room.roomNumber = number;
	room.bookStatus = status;
	room.roomGuest = guest;
	return room;
}

//Function to generate unbooked rooms
void createUnbookedRooms(ROOM rooms[], int numRooms) {
	for (int i = 0; i < numRooms; i++)
	{
		rooms[i] = createRoom(i + 1, UNBOOKED, createGuest(PLACEHOLDER, PLACEHOLDER));
	}
}

//Function to write all rooms to a file
void writeRooms(ROOM rooms[MAXROOMS], char* filename) {
	
	FILE* fp = fopen(filename, "w");

	// verify file opened
	if (!fp)
	{
		fprintf(stderr, "Error opening %s", filename);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAXROOMS; i++)
	{
		//Write rooms to file
		fprintf(fp, "ROOM\n");
		fprintf(fp, "Room Number: %d\n", rooms[i].roomNumber);
		fprintf(fp, "Book Status: %c\n", rooms[i].bookStatus);
		fprintf(fp, "%s\n", rooms[i].roomGuest.firstName);
		fprintf(fp, "%s\n", rooms[i].roomGuest.lastName);
		fprintf(fp, "\n");
	}

	fclose(fp);
}

//Function to read all rooms from a file
bool readRooms(ROOM rooms[], char* filename) {
	FILE* fp = fopen(filename, "r");

	//Verify file opened (existing and permissions available)
	if (!fp)
	{
		return false;
	}

	//Read rooms from file
	for (int i = 0; i < MAXROOMS; i++)
	{
		//Read the room indicator
		fscanf_s(fp, "ROOM\n");

		//Read the room number from file and verify
		if(fscanf_s(fp, "Room Number: %d\n", &rooms[i].roomNumber) != 1)
		{
			fprintf(stderr, "Error reading room number from file");
			exit(EXIT_FAILURE);
		}

		//Read the book status from file and verify
		if(fscanf_s(fp, "Book Status: %c\n", &rooms[i].bookStatus, 1) != 1)
		{
			fprintf(stderr, "Error reading book status from file");
			exit(EXIT_FAILURE);
		}

		//Read the guest from file and verify
		if(fscanf_s(fp, "%s\n", rooms[i].roomGuest.firstName, MAXNAME) != 1)
		{
			fprintf(stderr, "Error reading guest first name from file");
			exit(EXIT_FAILURE);
		}

		if(fscanf_s(fp, "%s\n", rooms[i].roomGuest.lastName, MAXNAME) != 1)
		{
			fprintf(stderr, "Error reading guest last name from file");
			exit(EXIT_FAILURE);
		}
		
		// read the newline from file
		fscanf_s(fp, "\n");
	}

	fclose(fp);

	return true;
}

//Option a) Show number of empty (unbooked) rooms
int numOfEmptyRooms(ROOM r[]) {
	int emptyRooms = 0;
	for (int i = 0; i <= MAXROOMS; i++)
	{
		//If room is unbooked add to emptyRooms
		if (r[i].bookStatus == UNBOOKED) emptyRooms++;
	}
	return emptyRooms;
}

//Option b) Show list of the empty (unbooked) rooms
void listEmptyRooms(ROOM r[]) {
	//Check for empty rooms
	for (int i = 0; i <= MAXROOMS; i++)
	{
		//If room is unbooked add to emptyRooms
		if (r[i].bookStatus == UNBOOKED)
		{
			//List empty rooms room numbers
			printf("\nRoom %d is unbooked.", r[i].roomNumber);
		}
	}
}

//Option d) Book a room to a guest
//Books next available room
ROOM bookRoomToGuest(ROOM r[], int numRooms, GUEST guest) {

	for (int i = 0; i < numRooms; i++) 
	{
		if (r[i].bookStatus == UNBOOKED) 
		{
			//Change book status and add guest
			r[i].bookStatus = BOOKED;
			r[i].roomGuest = guest;
			//Return the booked room
			return r[i]; 
		}
	}
	//If no available room is found, return a default room
	ROOM defaultRoom = { 0 };
	return defaultRoom;
}

void displaySortedGuests(ROOM* rooms, SORTTYPE sortType)
{
	//Get count of booked rooms
	int count = MAXROOMS - numOfEmptyRooms(rooms);

	//Create an array of guests
	GUEST* guests = (GUEST*)malloc(count * sizeof(GUEST));

	if (!guests)
	{
		fprintf(stderr, "Error allocating memory for guests");
		exit(EXIT_FAILURE);
	}

	//Copy the guests from the rooms to the array only if the room is booked
	for (int i = 0, counter = 0; i < MAXROOMS; i++)
	{
		if (rooms[i].bookStatus == BOOKED)
		{
			guests[counter++] = rooms[i].roomGuest;
		}
	}

	// sort the guests
	if (sortType == FIRSTNAME)
	{
		sortGuestsByFirstName(guests, count);
	}
	else
	{
		sortGuestsByLastName(guests, count);
	}

	//Print the guests
	printArrayOfGuests(guests, count);

	//Free the memory
	free(guests);
}

//Option e) Delete an existing room booking
void deleteBooking(ROOM* r) {
	// resets the room to unbooked
	*r = createRoom(r->roomNumber, UNBOOKED, createGuest(PLACEHOLDER, PLACEHOLDER));
}