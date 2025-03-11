#include "inputValidation.h"

//madisont - prog71985 - assign4, q2 - input validation implementation

//Verifying that the string contains at least one alpha char
//and that it doesn't contain any non-alpha chars
//Alphabetical input validation function
bool alphaValidation(char* nameInput)
{
    bool foundAnAlphaChar = false;

    for (int counter = 0; counter != strlen(nameInput); counter++)
    {
        if (!isalpha(nameInput[counter]) && nameInput[counter] != SPACE_CHAR)
        {
            //Return false if input isn't alphabetical (allowing spaces)
            return false;
        }
        else if (isalpha(nameInput[counter]))
        {
            //Verifying that the string contains at least one alpha char
            //And returning true if one is found
            foundAnAlphaChar = true;
        }
    }
    return foundAnAlphaChar;
}

//Get user input and perform all validations
//Validate name input function
bool validateNameInput(char* nameInput) {

    //Allow properly formatted strings with spaces but no empty input
    int result = scanf_s("%[^\n]s", nameInput, MAXNAME);

    //Check for empty input
    //Without second condition only '\n' input breaks the program
    if (result != 1 && result == EOF)
    {
        return false;
    }
    //Truncate trailing spaces and replace with \0 character
    for (int length = strlen(nameInput); nameInput[length - 1] == SPACE_CHAR; length--) {
        nameInput[length - 1] = '\0';
    }
    //Clear the input buffer for subsequent calls
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);

    //Program specific validation (no empty strings, only alpha chars/spaces)
    if (strlen(nameInput) > 0 && alphaValidation(nameInput)) {
        return true;
    }
    else {
        return false;
    }
}

int getAndValidateIntInput(char* message) {
    int input;
    bool isValid = false;

    do {
        //Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
		printf("%s", message);

        // get input and validate (excluding the abort value)
        if (scanf_s("%d", &input) != 1 || input < MINROOMS || input > MAXROOMS && input != ABORT_INT)
        {
            printf("Invalid input, please enter a number between %d and %d: ", MINROOMS, MAXROOMS);
        }
		else {
			isValid = true;
		}

	} while (!isValid);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

	return input;
}

//this is the most secure input validation I've ever created... it took me 6 hours of trial and error