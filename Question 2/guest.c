#define _CRT_SECURE_NO_WARNINGS
#include "guest.h"

//madisont - prog71985 - assign4, q2 - guest object implementation

//The program uses an array of 10 structures. Each structure should hold
//a room identification number, a marker that indicates whether the room
//is booked, and the first and last names of the booking guest

//Create Guest function
GUEST createGuest(char* first, char* last) {
	GUEST guest;
	strncpy(guest.firstName, first, MAXNAME);
	strncpy(guest.lastName, last, MAXNAME);
	return guest;
}

//Get Guest name(s) From Input function
bool getGuestNameInput(char message[], char name[MAXNAME]) {
	//Initialize name variable to be empty at the start of the function
	name[0] = '\0';
	//Initialize isValid variable as false
	bool isValid = false;

	do {
		//Print prompt message
		printf("\n%s", message);
		//Get name input from user and validate
		isValid = validateNameInput(name);

		// if the user enters the abort keyword, return to the menu
		if(!strcmp(name, ABORT_STR)) {
			printf("\nYou have selected to abort the action, going back to the main menu...\n\n");
			return false;
		}

		// if the input is invalid, continue prompting the user
		if (!isValid)
		{
			printf("ERROR: Invalid input\n");
		}
	} while (!isValid);

	return true;
}

void saveGuestToDisk(GUEST g, FILE* fp) {
	fprintf(fp, "GUEST\n");
	fprintf(fp, "%s\n", g.firstName);
	fprintf(fp, "%s\n", g.lastName);
}

//Option c) Show alphabetical listing of guests who have booked a room
//Option a) Sort by first name
void sortGuestsByFirstName(GUEST guests[], int numGuests) {
	GUEST temp;

	for (int i = 0; i < numGuests - 1; i++)
	{
		for (int j = i + 1; j < numGuests; j++)
		{
			if (strcmp(guests[i].firstName, guests[j].firstName) > 0)
			{
				temp = guests[i];
				guests[i] = guests[j];
				guests[j] = temp;
			}
		}
	}
}

//Option c) Show alphabetical listing of guests who have booked a room
//Option b) Sort by last name
void sortGuestsByLastName(GUEST guests[], int numGuests) {
	GUEST temp;

	//Use bubble sort in alphabetical order
	for (int i = 0; i < numGuests - 1; i++)
	{
		for (int j = i + 1; j < numGuests; j++)
		{
			if (strcmp(guests[i].lastName, guests[j].lastName) > 0)
			{
				temp = guests[i];
				guests[i] = guests[j];
				guests[j] = temp;
			}
		}
	}
}

void printArrayOfGuests(GUEST g[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%s %s\n", g[i].firstName, g[i].lastName);
	}
}

void DeleteGuest(GUEST g) {
	//nothing here
}