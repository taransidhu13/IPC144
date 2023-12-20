/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main() {
    char loopType;
    int numIterations;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &numIterations);

        if (loopType == 'Q' && numIterations == 0) {
            printf("\n");
            break;
        }

        if (loopType != 'D' && loopType != 'W' && loopType != 'F' && loopType != 'Q') {
            printf("ERROR: Invalid entered value(s)!\n\n");
            continue;
        }

        if (loopType == 'Q' && (numIterations < 3 || numIterations > 20)) {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            continue;
        }

        if (numIterations < 3 || numIterations > 20) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            continue;
        }


        switch (loopType) {
        case 'D':
            printf("DO-WHILE: ");
            do {
                printf("D");
                numIterations--;
            } while (numIterations > 0);
            printf("\n\n");
            break;
        case 'W':
            printf("WHILE   : ");
            while (numIterations > 0) {
                printf("W");
                numIterations--;
            }
            printf("\n\n");
            break;
        case 'F':
            printf("FOR     : ");
            for (; numIterations > 0; numIterations--) {
                printf("F");
            }
            printf("\n\n");
            break;
        }

        
    } while (loopType != 'Q' || numIterations != 0);
    

    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}