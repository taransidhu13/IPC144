/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// This function formats and displays an array of 10-character digits as a phone number.
void displayFormattedPhone(const char* str);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function ensures valid input by accepting only integer values and displaying an error message for invalid input.
int inputInt(void);

// This function enforces positive integer input, displaying an error message for zero or negative values.
int inputIntPositive(void);

// This function ensures the input is an integer within a specified range, displaying an error message for out-of-range values until a valid input is received.
int inputIntRange(int lowerLimit, int upperLimit);

// This function ensures the input is a single character from a list of valid characters, displaying an error message for invalid characters until a valid input is received.
char inputCharOption(char str[]);

// This function ensures the input is a C string with a length within the specified range, as defined by the 2nd and 3rd arguments.
void inputCString(char* str, int minimumChar, int maximumChar);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
