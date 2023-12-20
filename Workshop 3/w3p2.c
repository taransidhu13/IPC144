/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    
        // Variable declarations
        int coffee1Light, coffee1Medium, coffee1Rich;
        int coffee2Light, coffee2Medium, coffee2Rich;
        int coffee3Light, coffee3Medium, coffee3Rich;
        int coffee1BagWeight, coffee2BagWeight, coffee3BagWeight;
        double coffee1WeightLbs, coffee2WeightLbs, coffee3WeightLbs;
        int coffee1Cream, coffee2Cream, coffee3Cream;
        char preferenceStrength, preferenceCream;
        int preferenceServings;

        // Product data input
        printf("Enter the coffee product information being sold today...\n");

        printf("COFFEE-1...\n");
        printf("Type ([L]ight,[M]edium,[R]ich): ");
        scanf(" %c", &preferenceStrength);
        printf("Bag weight (g): ");
        scanf("%d", &coffee1BagWeight);
        printf("Best served with cream ([Y]es,[N]o): ");
        scanf(" %c", &preferenceCream);

        printf("COFFEE-2...\n");
        printf("Type ([L]ight,[M]edium,[R]ich): ");
        scanf(" %c", &preferenceStrength);
        printf("Bag weight (g): ");
        scanf("%d", &coffee2BagWeight);
        printf("Best served with cream ([Y]es,[N]o): ");
        scanf(" %c", &preferenceCream);

        printf("COFFEE-3...\n");
        printf("Type ([L]ight,[M]edium,[R]ich): ");
        scanf(" %c", &preferenceStrength);
        printf("Bag weight (g): ");
        scanf("%d", &coffee3BagWeight);
        printf("Best served with cream ([Y]es,[N]o): ");
        scanf(" %c", &preferenceCream);

        // Determine the values for coffee1Light, coffee1Medium, coffee1Rich
        coffee1Light = (preferenceStrength == 'L') || (preferenceStrength == 'l');
        coffee1Medium = (preferenceStrength == 'M')|| (preferenceStrength == 'm');
        coffee1Rich = (preferenceStrength == 'R') || (preferenceStrength == 'r');

        // Determine the values for coffee2Light, coffee2Medium, coffee2Rich
        coffee2Light = (preferenceStrength == 'L')|| (preferenceStrength == 'l');
        coffee2Medium = (preferenceStrength == 'M') || (preferenceStrength == 'm');
        coffee2Rich = (preferenceStrength == 'R') || (preferenceStrength == 'r');

        // Determine the values for coffee3Light, coffee3Medium, coffee3Rich
        coffee3Light = (preferenceStrength == 'L') || (preferenceStrength == 'l');
        coffee3Medium = (preferenceStrength == 'M') || (preferenceStrength == 'm');
        coffee3Rich = (preferenceStrength == 'R') || (preferenceStrength == 'r');

        // Display product data
        printf("---+------------------------+---------------+-------+\n");
        printf(" | Coffee | Packaged | Best |\n");
        printf(" | Type | Bag Weight | Served|\n");
        printf(" +------------------------+---------------+ With |\n");
        printf("ID | Light | Medium | Rich | (G) | Lbs | Cream |\n");
        printf("---+------------------------+---------------+-------|\n");
        printf("1 | %d | %d | %d | %4d | %6.3lf | %d |\n",
            coffee1Light, coffee1Medium, coffee1Rich, coffee1BagWeight, coffee1BagWeight * GRAMS_IN_LBS, (preferenceCream == 'Y'));
        printf("2 | %d | %d | %d | %4d | %6.3lf | %d |\n",
            coffee2Light, coffee2Medium, coffee2Rich, coffee2BagWeight, coffee2BagWeight * GRAMS_IN_LBS, (preferenceCream == 'Y'));
        printf("3 | %d | %d | %d | %4d | %6.3lf | %d |\n",
            coffee3Light, coffee3Medium, coffee3Rich, coffee3BagWeight, coffee3BagWeight * GRAMS_IN_LBS, (preferenceCream == 'Y'));
        printf("---+------------------------+---------------+-------|\n");

        // Customer preference input (1st time)
        printf("Enter how you like your coffee...\n");
        printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
        scanf(" %c", &preferenceStrength);
        printf("Do you like your coffee with cream ([Y]es,[N]o): ");
        scanf(" %c", &preferenceCream);
        printf("Typical number of daily servings: ");
        scanf("%d", &preferenceServings);

        // Display summary of results (1st time)
        printf("The below table shows how your preferences align to the available products:\n");
        printf("--------------------+-------------+-------+\n");
        printf(" | Coffee | Packaged | With |\n");
        printf("ID| Type | Bag Weight | Cream |\n");
        printf("--+-----------------+-------------+-------+\n");
        printf("1 | %d | %d | %d |\n",
            (preferenceStrength == 'L' && coffee1Light == 1),
            (preferenceStrength == 'M' && coffee1Medium == 1),
            (preferenceStrength == 'R' && coffee1Rich == 1));
        printf("2 | %d | %d | %d |\n",
            (preferenceStrength == 'L' && coffee2Light == 1),
            (preferenceStrength == 'M' && coffee2Medium == 1),
            (preferenceStrength == 'R' && coffee2Rich == 1));
        printf("3 | %d | %d | %d |\n",
            (preferenceStrength == 'L' && coffee3Light == 1),
            (preferenceStrength == 'M' && coffee3Medium == 1),
            (preferenceStrength == 'R' && coffee3Rich == 1));
        printf("--------------------+-------------+-------+\n");

        // Customer preference input (2nd time)
        printf("Enter how you like your coffee...\n");
        printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
        scanf(" %c", &preferenceStrength);
        printf("Do you like your coffee with cream ([Y]es,[N]o): ");
        scanf(" %c", &preferenceCream);
        printf("Typical number of daily servings: ");
        scanf("%d", &preferenceServings);

        // Display summary of results (2nd time)
        printf("The below table shows how your preferences align to the available products:\n");
        printf("--------------------+-------------+-------+\n");
        printf(" | Coffee | Packaged | With |\n");
        printf("ID| Type | Bag Weight | Cream |\n");
        printf("--+-----------------+-------------+-------+\n");
        printf("1 | %d | %d | %d |\n",
            (preferenceStrength == 'L' && coffee1Light == 1),
            (preferenceStrength == 'M' && coffee1Medium == 1),
            (preferenceStrength == 'R' && coffee1Rich == 1));
        printf("2 | %d | %d | %d |\n",
            (preferenceStrength == 'L' && coffee2Light == 1),
            (preferenceStrength == 'M' && coffee2Medium == 1),
            (preferenceStrength == 'R' && coffee2Rich == 1));
        printf("3 | %d | %d | %d |\n",
            (preferenceStrength == 'L' && coffee3Light == 1),
            (preferenceStrength == 'M' && coffee3Medium == 1),
            (preferenceStrength == 'R' && coffee3Rich == 1));
        printf("--------------------+-------------+-------+\n");

        printf("Hope you found a product that suits your likes!\n");

        return 0;
    }