#pragma once
#include "inputValidation.h"
#include <string.h>
#include <stdio.h>

//madisont - prog71985 - assign4, q2 - guest implementation

//Guest Library
#ifndef GUEST_LIBRARY_H
#define GUEST_LIBRARY_H

typedef struct hotelGuest {
	char lastName[MAXNAME];
	char firstName[MAXNAME];
}GUEST;

//Create Guest
GUEST createGuest(char* first, char* last);

//Get Guest Name
bool getGuestNameInput(char message[], char name[MAXNAME]);

//Save Guest to disk
void saveGuestToDisk(GUEST g, FILE* fp);

//Option c) Show alphabetical listing of guests who have booked a room
//Option a) Sort by first name
void sortGuestsByFirstName(GUEST*, int);

//Option c) Show alphabetical listing of guests who have booked a room
//Option b) Sort by last name
void sortGuestsByLastName(GUEST*, int);

void DeleteGuest(GUEST g);

#endif //GUEST_LIBRARY_H