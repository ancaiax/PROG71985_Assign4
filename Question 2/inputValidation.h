#pragma once
#define MAXNAME 30
#define SPACE_CHAR ' '
#define MINROOMS 1
#define MAXROOMS 10
#define ABORT_STR "abort\0"
#define ABORT_INT -1
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//madisont - prog71985 - assign4, q2 - input validaiton library

#ifndef INPUT_VALIDATION_LIBRARY_H
#define INPUT_VALIDATION_LIBRARY_H

bool alphaValidation(char* input);

bool validateNameInput(char* nameInput);

int getAndValidateIntInput(char*);

#endif //INPUT_VALIDATION_LIBRARY_H