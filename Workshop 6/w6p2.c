/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define MAX_ITEMS 10
#define MIN_COST 100.00

int main(void)
{
    double income;
    int numItems;
    double cost[MAX_ITEMS];
    int priority[MAX_ITEMS];
    char finance[MAX_ITEMS];
    int i;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    // monthly NET income
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < MIN_INCOME)
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
        else if (income > MAX_INCOME)
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);
    } while (income < MIN_INCOME || income > MAX_INCOME);

    printf("\n");

    // number of wish list items
    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);

        if (numItems < 1 || numItems > MAX_ITEMS)
            printf("ERROR: List is restricted to between 1 and %d items.\n\n", MAX_ITEMS);
    } while (numItems < 1 || numItems > MAX_ITEMS);
    printf("\n");

    // Store the wish list item details
    for (i = 0; i < numItems; i++) {
        printf("Item-%d Details:\n", i + 1);

        // Prompt for item cost
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < MIN_COST)
                printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
        } while (cost[i] < MIN_COST);

        // item priority
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
                printf("      ERROR: Value must be between 1 and 3\n");
        } while (priority[i] < 1 || priority[i] > 3);

        // finance options
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (finance[i] != 'y' && finance[i] != 'n')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (finance[i] != 'y' && finance[i] != 'n');
        printf("\n");
    }


    // table 
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numItems; i++) {
        printf("%3d %6d %8c %14.2lf\n", i + 1, priority[i], finance[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");

    // Calculate the total cost
    double totalCost = 0.0;
    for (i = 0; i < numItems; i++) {
        totalCost += cost[i];
    }
    printf("                      $%11.2lf\n\n", totalCost);

    int menuSelection;
    int fPriority;
    
    

    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &menuSelection);
        printf("\n");

        if (menuSelection == 1) {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);

            int years = (int)(totalCost / (income * 12));
            int months = (int)((totalCost / (income * 12) - years) * 12 + 0.9);

            printf("Forecast: %d years, %d months\n", years, months);


            printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");

            printf("====================================================\n");
            printf("\n");
        }
        else if (menuSelection == 2) {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &fPriority);
            printf("\n");

            if (fPriority < 1 || fPriority > 3) {
                printf("ERROR: Invalid priority level. Please enter a value between 1 and 3.\n");
                printf("\n");
                continue;
            }

            double fCost = 0.0;
            int fCount = 0;
            int fFinanceOption = 0;

            for (i = 0; i < numItems; i++) {
                if (priority[i] == fPriority) {
                    fCost += cost[i];
                    fCount++;

                    if (finance[i] == 'y')
                        fFinanceOption = 1;
                }
            }

            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", fPriority);
            printf("Amount:   $%.2lf\n", fCost);

            int years = (int)((fCost / (income * 12)));
            int months = (int)(((fCost / (income * 12) - years) * 12) + 0.9);

            printf("Forecast: %d years, %d months\n", years, months);

            if (fFinanceOption)
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");

            printf("====================================================\n\n");
        }
        else if (menuSelection != 0) {
            printf("ERROR: Invalid menu selection.\n\n");
        }
    } while (menuSelection != 0);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}