/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : TARANDEEP KAUR
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

int main() {
    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    int isValidYear = 0;
    int isValidMonth = 0;

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
     printf("Log starting date: %d-", year);

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

     printf("-01\n");

     return 0;
}