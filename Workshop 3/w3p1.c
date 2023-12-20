/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZDD
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    int pdct1ID = 111, pdct2ID = 222, pdct3ID = 111;
    double pdct1P = 111.49, pdct2P = 222.99, pdct3P = 334.49;
    const char pdct1T = 'Y', pdct2T = 'N', pdct3T = 'N';
   

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", pdct1ID);
    printf("  Taxed: %c\n", pdct1T);
    printf("  Price: $%.4lf\n", pdct1P);
    printf("\n");
    printf("Product-2 (ID:%d)\n", pdct2ID);
    printf("  Taxed: %c\n", pdct2T);
    printf("  Price: $%.4lf\n", pdct2P);
    printf("\n");
    printf("Product-3 (ID:%d)\n", pdct3ID);
    printf("  Taxed: %c\n", pdct3T);
    printf("  Price: $%.4lf\n", pdct3P);
    printf("\n");
    printf("The average of all prices is: $%.4lf\n", (pdct1P + pdct2P + pdct3P) / 3);
    printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", pdct1T != 'N');
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", pdct2T == 'N' && pdct3T == 'N');
    printf("\n");
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n", pdct3P < testValue);
    printf("\n");
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", pdct3P > (pdct1P + pdct2P));
    printf("\n");
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", pdct1P >= (pdct3P - pdct2P), pdct3P - pdct2P);
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", pdct2P >= (pdct1P + pdct2P + pdct3P) / 3);
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n", pdct1ID != pdct2ID && pdct1ID != pdct3ID);
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n", pdct2ID != pdct1ID && pdct2ID != pdct3ID);
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n", pdct3ID != pdct1ID && pdct3ID != pdct2ID);
    return 0;
}