/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

void displayFormattedPhone(const char* str)
{
    int length = 0;
    int i;
    int isdigit(int str);

    while (str != NULL && str[length] && isdigit(str[length])) {
        length++;
    }
    if (length == 10) {
        i = 0;
        printf("(");
        while (i < 3) {
            printf("%c", str[i]);
            i++;
        }
        printf(")");
        while (i < 6) {
            printf("%c", str[i]);
            i++;
        }
        printf("-");
        while (i < 10) {
            printf("%c", str[i]);
            i++;
        }
    }
    else {
        printf("(___)___-____");
    }
    if (str != 0) {
        for (i = 0; str[i] != '\0'; i++)
            length++;
    }

}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function ensures valid input by accepting only integer values and displaying an error message for invalid input.
int inputInt(void)
{
    int input, valid;
    char newline = 'a';

    do {
        scanf("%d%c", &input, &newline);
        valid = newline == '\n' ? 1 : 0;
        if (!valid)
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (!valid);

    return input;
}


// This function enforces positive integer input, displaying an error message for zero or negative values.
// Guarantees a positive integer value is input by the user
int inputIntPositive(void)
{
    int input, valid;
    do {
        input = inputInt();
        valid = input > 0;
        if (!valid)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (!valid);

    return input;
}

// This function ensures the input is an integer within a specified range, displaying an error message for out-of-range values until a valid input is received.
int inputIntRange(int min, int max)
{
    int input, valid;

    do
    {
        input = inputInt();
        valid = !(input < min || input > max);
        if (!valid)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
    } while (!valid);

    return input;
}

// This function ensures the input is a single character from a list of valid characters, displaying an error message for invalid characters until a valid input is received.
char inputCharOption(char str[]) {
    int i, number = 0;
    char userInput;

    do {
        scanf(" %c", &userInput);

        for (i = 0; str[i] != '\0'; i++) {
            if (userInput == str[i]) {
                number++;
            }
        }

        if (number == 0) {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (number == 0);

    clearInputBuffer();
    return userInput;
}

// This function ensures the input is a C string with a length within the specified range, as defined by the 2nd and 3rd arguments.
void inputCString(char* str, int minimumChar, int maximumChar) {
    int flag = 1;
    char chrcter = 'a';

    while (flag) {
        int length = 0;

        while (chrcter != '\n' && length <= maximumChar) {
            chrcter = getchar();
            str[length] = chrcter;
            length++;
        };

        // If the length of the string is less than or equal to maximumChars, this function terminates the string with the null character('\0') to mark the end of the string.

        if (chrcter == '\n' && length <= (maximumChar + 1)) {
            length--;
            str[length] = '\0';
        }
        // This function truncates the string to maximumChar characters, adding '\0' at the end, and removes any extra characters from the buffer.
        else {
            str[maximumChar] = '\0';
            clearInputBuffer();
        }

        if (minimumChar == maximumChar && length != minimumChar) {
            printf("Invalid 10-digit number! Number: ");
            chrcter = 'a';
        }
        else if (length < minimumChar || length > maximumChar) {
            if (length > maximumChar) {
                printf("ERROR: String length must be no more than %d chars: ", maximumChar);
                chrcter = 'a';
            }
            else if (length < minimumChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minimumChar, maximumChar);
                chrcter = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}
