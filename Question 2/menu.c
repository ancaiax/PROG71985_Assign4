#include "menu.h"
#include <stdio.h>
#include <string.h>

//madisont - prog71985 - assign4, q2 - menu implementation

void printWelcomeMenu() {
	printf(" *************************** \n");
	printf("**   Welcome to StayRite   **\n");
	printf("**      Hotel Booking      **\n");
	printf(" *************************** \n");
}

//The program displays the following menu (specification)
void printOptions() {
	printf("\nTo choose a function, enter its label:\n");
	printf("a) Show number of empty (unbooked) rooms\n");
	printf("b) Show list of the empty (unbooked) rooms\n");
	printf("c) Show alphabetical listing of guests who have booked a room\n");
	printf("d) Book a room to a guest\n");
	printf("e) Delete an existing room booking \n");
	printf("f) Quit\n");
}

void printCaseCOptions() {
	printf("\na) Sort by first name\n");
	printf("b) Sort by last name\n");
}

char getCharInput(char message[]) {
	char menuInput[MAXCHAR];
	printf("\n%s\n", message);
	fgets(menuInput, MAXCHAR, stdin);
	return menuInput[0];
}