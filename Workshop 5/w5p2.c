/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main() {
    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    int isValidYear = 0;
    int isValidMonth = 0;
    double morningRating, eveningRating;
    double morningTotal = 0.0, eveningTotal = 0.0, overallTotal = 0.0;
    int day;

    printf("General Well-being Log\n");
    printf("======================\n");

    while (!isValidYear || !isValidMonth) {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC)) {
            isValidYear = 1;
            isValidMonth = 1;
        }
        else if ((year < MIN_YEAR || year > MAX_YEAR) && (month >= JAN && month <= DEC)) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        else if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month < JAN || month > DEC)) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }


        else {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            continue;
        }
    }

    printf("\n");

    printf("*** Log date set! ***\n");
    printf("\n");
   
  

    for (day = 1; day <= LOG_DAYS; day++) {
        printf("%d-", year);

        if (month == 1) {
            printf("JAN");
        }
        else if (month == 2) {
            printf("FEB");
        }
        else if (month == 3) {
            printf("MAR");
        }
        else if (month == 4) {
            printf("APR");
        }
        else if (month == 5) {
            printf("MAY");
        }
        else if (month == 6) {
            printf("JUN");
        }
        else if (month == 7) {
            printf("JUL");
        }
        else if (month == 8) {
            printf("AUG");
        }
        else if (month == 9) {
            printf("SEP");
        }
        else if (month == 10) {
            printf("OCT");
        }
        else if (month == 11) {
            printf("NOV");
        }
        else if (month == 12) {
            printf("DEC");
        }

        printf("-%02d\n", day);

        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);

            if (morningRating < 0.0 || morningRating > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0.0 || morningRating > 5.0);

        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);

            if (eveningRating < 0.0 || eveningRating > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating > 5.0);

        morningTotal += morningRating;
        eveningTotal += eveningRating;
        overallTotal += morningRating + eveningRating;

        printf("\n");
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating:  %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", overallTotal);
    printf("\n");
    printf("Average morning rating:  %.1lf\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", overallTotal / (LOG_DAYS * 2));

    return 0;
}
