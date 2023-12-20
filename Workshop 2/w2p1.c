/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    //declare variables for prices of shirts
    int nShirts;
    double psmallShirt, pmediumShirt, plargeShirt;


    //get prices of shirts from user
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &psmallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &pmediumShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &plargeShirt);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", psmallShirt);
    printf("MEDIUM : $%.2lf\n", pmediumShirt);
    printf("LARGE  : $%.2lf\n", plargeShirt);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nShirts);
    printf("\n");

    int sub_total = ((psmallShirt * 100) * nShirts);
    int taxes = ((sub_total * TAX) + 1);
    int total = sub_total + taxes;

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", nShirts);
    printf("Sub-total: $%d.%02d00\n", sub_total / 100, sub_total % 100);
    printf("Taxes    : $ %d.%02d00\n", taxes / 100, taxes % 100);
    printf("Total    : $%d.%02d00\n", total / 100, total % 100);


    return 0;
}