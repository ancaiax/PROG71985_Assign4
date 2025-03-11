#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "HotelBooking.txt"
#include "menu.h"
#include "rooms.h"
#include "guest.h"
#include "inputValidation.h"
#include <stdbool.h>

//madisont - prog71985 - assign4, q2

//The StayRite Hotel Company consists of a single hotel with a room capacity
//of 10. Guests may only stay at the hotel 1 night and each room can only
//accommodate 1 guest.
//After executing a particular function, the program should print the menu 
//again and wait for input.
//The program successfully executes the promise of each command on its
//menu.
//Choice c) will list the guests in alphabetic order, either by first or last
//name(selected by user during program execution).
//Choices d) and e) require additional input, and each choice should prompt
//the user to enter the required data or abort the action.
//(f)After executing a particular function(options a) - e)), the program should
//print the menu again and wait for input.Upon selecting f), the program
//should exit.

//Data is saved in a file between runs. When the program is (re)started, it
//will first attempt to read the data file and populate itself with that data;
//if there is no existing datafile, the program will create a new one with no data
//populated


/*ROOM rooms[MAXROOMS] = {
	createRoom(1, BOOKED, createGuest("", "")),
	createRoom(2, UNBOOKED, createGuest("", "")),
	createRoom(3, UNBOOKED, createGuest("", "")),
	createRoom(4, BOOKED, createGuest("", "")),
	createRoom(5, UNBOOKED, createGuest("", "")),
	createRoom(6, UNBOOKED, createGuest("", "")),
	createRoom(7, UNBOOKED, createGuest("", "")),
	createRoom(8, UNBOOKED, createGuest("", "")),
	createRoom(9, BOOKED, createGuest("", "")),
	createRoom(10, UNBOOKED, createGuest("", ""))
};*/

void main() {

	//Array of rooms
	ROOM rooms[MAXROOMS];
	//Flag to continue program
	bool continueProgram = true;
	//Read rooms from file
	bool dataRead = readRooms(rooms, FILENAME);

	// if no content was read, generate unbooked rooms
	if (!dataRead)
	{
		//Create empty rooms
		createUnbookedRooms(rooms, MAXROOMS);
	}
	
	while (continueProgram) {

		int roomNumber;
		int num;
		char menuInput = '\0';

		printWelcomeMenu();
		printOptions();

		menuInput = getCharInput("Enter menu option letter:");

		//Variables for option d
		GUEST g;
		ROOM bookedRoom;

		switch (menuInput)
		{
		case 'a':
			//Show number of unbooked rooms
			num = numOfEmptyRooms(rooms);
			printf("\nThere are %d empty rooms.\n\n\n", num);
			break;
		case 'b':
			//List unbooked rooms

			listEmptyRooms(rooms);
			printf("\n\n\n");
			break;
		case 'c':
			printCaseCOptions();
			char menuInputC = '\0';
			menuInputC = getCharInput("Enter menu option letter for sorting:");
			switch (menuInputC)
			{
			case 'a':
				//Sort by first name
				displaySortedGuests(rooms, FIRSTNAME);
				break;
			case 'b':
				//Sort by last name
				displaySortedGuests(rooms, LASTNAME);
				break;
			default:
				printf("\nInvalid option entered.\n\n");
				break;
			};
			break;
		case 'd':
			//Get Guest's first and last names
			if (getGuestNameInput("Enter Guest's first name (enter abort to go back to the menu): \n", g.firstName))
			{
				if (getGuestNameInput("Enter Guest's last name (enter abort to go back to the menu):\n", g.lastName))
				{
					//Create Guest and Save to Disk
					g = createGuest(g.firstName, g.lastName);
					//saveGuestToDisk(g, fptr)

					//Book Room to Guest
					bookedRoom = bookRoomToGuest(rooms, MAXROOMS, g);

					//Default room (0) is returned if no unbooked rooms are found
					if (bookedRoom.roomNumber != 0)
					{

						printf("\nRoom %d booked for guest %s %s.\n\n", bookedRoom.roomNumber, g.firstName, g.lastName);
					}
					else
					{
						printf("No available rooms found.\n");
					}
				}
			}
			break;
		case 'e':
			roomNumber = getAndValidateIntInput("Enter room number to delete booking: ");

			//Delete Room Booking
			deleteBooking(&rooms[roomNumber - 1]);

			printf("\nRoom %d booking deleted.\n\n", roomNumber);
			break;
		case 'f':
			printf("Thank you for using StayRite Hotel Booking!\nQuitting...\n");
			continueProgram = false;
			break;
		default:
			printf("\nInvalid option entered.\n\n");
			break;
		};
	};

	writeRooms(rooms, FILENAME); // save all changes to file
}