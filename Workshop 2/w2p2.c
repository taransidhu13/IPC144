/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    //declare variables for prices of shirts
    int nsmallShirts, nmediumShirts, nlargeShirts;
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
    scanf("%d", &nsmallShirts);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &nlargeShirts);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &nmediumShirts);
    printf("\n");

    int pattySubTotal = (int)(psmallShirt * 100) * nsmallShirts;
    int pattyTaxes = (int)((pattySubTotal * TAX) + 0.5);
    int pattyTotal = pattySubTotal + pattyTaxes;

    int sallySubTotal = (int)(pmediumShirt * 100) * nmediumShirts;
    int sallyTaxes = (int)((sallySubTotal * TAX) + 0.5);
    int sallyTotal = sallySubTotal + sallyTaxes;

    int tommySubTotal = (int)(plargeShirt * 100) * nlargeShirts;
    int tommyTaxes = (int)((tommySubTotal * TAX) + 0.5);
    int tommyTotal = tommySubTotal + tommyTaxes;



    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, psmallShirt, nsmallShirts, pattySubTotal / 100.0, pattyTaxes / 100.0, pattyTotal / 100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, pmediumShirt, nmediumShirts, sallySubTotal / 100.0, sallyTaxes / 100.0, sallyTotal / 100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, plargeShirt, nlargeShirts, tommySubTotal / 100.0, tommyTaxes / 100.0, tommyTotal / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    int fsub_total = pattySubTotal + sallySubTotal + tommySubTotal;
    int totalSales = pattyTotal + sallyTotal + tommyTotal;
    int totalTaxes = pattyTaxes + sallyTaxes + tommyTaxes;

    printf("%33.4lf %9.4lf %9.4lf\n\n", fsub_total / 100.0, totalTaxes / 100.0, totalSales / 100.0);
   

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", fsub_total / 100.0);

    int toonies = fsub_total / 200;
    double balance = (double)fsub_total/100 - toonies*2;
    printf("Toonies  %3d %9.4lf\n", toonies, balance);

    int loonies = balance / 1.0;
    balance -= loonies * 1;
    printf("Loonies  %3d %9.4lf\n", loonies, balance);

    int quarters = balance / 0.25;
    balance -= quarters * 0.25;
    printf("Quarters %3d %9.4lf\n", quarters, balance);

    int dimes = balance / 0.1;
    balance -= dimes * 0.1;
    printf("Dimes    %3d %9.4lf\n", dimes, balance);

    int nickels = balance / 0.05;
    balance -= nickels * 0.05;
    printf("Nickels  %3d %9.4lf\n", nickels, balance);

    int pennies = balance / 0.01 + 1;
    printf("Pennies  %3d %9.4lf\n", pennies, 0.0);
    printf("\n");

    
    printf("Average cost/shirt: $%.4lf\n", (double)fsub_total / 100 / ((double)nsmallShirts + (double)nmediumShirts + (double)nlargeShirts));
    printf("\n");
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", totalSales / 100.0);

    toonies = totalSales / 200;
    balance = (double)totalSales / 100 - toonies * 2;
    printf("Toonies  %3d %9.4lf\n", toonies, balance);

    loonies = balance / 1.0;
    balance -= loonies * 1;
    printf("Loonies  %3d %9.4lf\n", loonies, balance);

    quarters = balance / 0.25;
    balance -= quarters * 0.25;
    printf("Quarters %3d %9.4lf\n", quarters, balance);

    dimes = balance / 0.1;
    balance -= dimes * 0.1;
    printf("Dimes    %3d %9.4lf\n", dimes, balance);

    nickels = balance / 0.05;
    balance -= nickels * 0.05;
    printf("Nickels  %3d %9.4lf\n", nickels, balance);

    pennies = balance / 0.01 + 1;
    printf("Pennies  %3d %9.4lf\n", pennies, 0.0);
    printf("\n");

    printf("Average cost/shirt: $%.4lf\n", (double)totalSales / 100 / ((double)nsmallShirts + (double)nmediumShirts + (double)nlargeShirts));

    return 0;
}