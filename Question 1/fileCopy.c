#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
//defining macros for argument position
#define ONE 0
#define TWO 1
#define THREE 2
#define BYTE 1
#define BUFFSIZE 1000

//madisont - prog71985 - assign4, q1

//Write a file copy program that takes 2 command line parameters : 1) the name
//of an existing text file and 2) the name of file to be created by your program.
//The program should use the toupper() function from ctype.h to convert all text
//in the file used as parameter 1 to uppercase as its written to the output file
//(parameter 2).Use standard I/O and access the files in text mode

int main(int argc, char* argv[]) {
	
	//Check for the correct number of arguments
	if (argc != 3)
	{
		//First argument contains the name of the program --> argv[0]
		printf("Usage: %s>fileCopy.c inputFile.txt <outputFile>.txt\n", argv[ONE]);
		return 1;
	}

	//Second argument is to read the inputFile --> argv[1]
	FILE* inputFile = fopen(argv[TWO], "r");
	//Check if file exists/failed to open
	if (inputFile == NULL)
	{
		printf("ERROR: Unable to open input file\n");
		return 1;
	}

	//Assign a specific name to the file copy on open/create attempt
	FILE* outputFile = fopen(argv[THREE], "w");
	//Check if file failed to open/be created
	if (outputFile == NULL) 
	{
		printf("ERROR: Unable to open output file\n");
		//Close the open inputFile if outputFile fails to open/be created
		fclose(inputFile);
		return 1;
	}

	//Allocate and initialize a buffer for fread(...)
	char buffer[BUFFSIZE] = { 0 };

	//Read inputFile.txt, convert text to uppercase, copy to outputFile
	int readBytes;

	while ((readBytes = fread(buffer, BYTE, BUFFSIZE, inputFile)) > 0) {
		//Continue the loop as long as fread() reads bytes into the buffer
		for (int i = 0; i < readBytes; i++) {
			//Loop through each character in the buffer and convert to uppercase
			buffer[i] = toupper(buffer[i]);
		}
		//Write uppercase converted text to outputFile
		fwrite(buffer, BYTE, readBytes, outputFile);
	}

	//Close both files
	fclose(inputFile);
	fclose(outputFile);

	printf("File copy successful!\n");

	return 0;
}