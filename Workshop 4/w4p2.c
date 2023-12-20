/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZDD
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    
    int shoppingDone = 0;

    while (!shoppingDone) {
        int apples, oranges, pears, tomatoes, cabbages;
        int pickApples, pickOranges, pickPears, pickTomatoes, pickCabbages;

        printf("Grocery Shopping\n");
        printf("================\n");

        // Set the quantities needed for each item
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        while (apples < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        }
        printf("\n");

        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        while (oranges < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
        }
        printf("\n");

        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        while (pears < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
        }
        printf("\n");

        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        while (tomatoes < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        }
        printf("\n");

        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        while (cabbages < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
        }
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        // Picking stage
        if (apples > 0) {
            while (apples > 0) {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickApples);
                while (pickApples < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                    printf("Pick some APPLES... how many did you pick? : ");
                    scanf("%d", &pickApples);
                }
                if (pickApples == apples) {
                    printf("Great, that's the apples done!\n\n");
                    apples = 0;
                }

                else if (pickApples < apples) {
                    printf("Looks like we still need some APPLES...\n");
                    apples -= pickApples;
                    continue;
                }

                else {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                    continue;
                }
            }
        }

        if (oranges > 0) {
            while (oranges > 0) {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickOranges);
                while (pickOranges < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                    printf("Pick some ORANGES... how many did you pick? : ");
                    scanf("%d", &pickOranges);
                }
                if (pickOranges == oranges) {
                    printf("Great, that's the oranges done!\n\n");
                    oranges = 0;
                }

                else if (pickOranges < oranges) {
                    printf("Looks like we still need some ORANGES...\n");
                    oranges -= pickOranges;
                    continue;
                }

                else {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                    continue;
                }
            }
        }

        if (pears > 0) {
            while (pears > 0) {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickPears);
                while (pickPears < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                    printf("Pick some PEARS... how many did you pick? : ");
                    scanf("%d", &pickPears);
                }
                if (pickPears == pears) {
                    printf("Great, that's the pears done!\n\n");
                    pears = 0;
                }

                else if (pickPears < pears) {
                    printf("Looks like we still need some PEARS...\n");
                    pears -= pickPears;
                    continue;
                }

                else {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                    continue;
                }
            }
        }

        if (tomatoes > 0) {
            while (tomatoes > 0) {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickTomatoes);
                while (pickTomatoes < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                    printf("Pick some TOMATOES... how many did you pick? : ");
                    scanf("%d", &pickTomatoes);
                }
                if (pickTomatoes == tomatoes) {
                    printf("Great, that's the tomatoes done!\n\n");
                    tomatoes = 0;
                }

                else if (pickTomatoes < tomatoes) {
                    printf("Looks like we still need some TOMATOES...\n");
                    tomatoes -= pickTomatoes;
                    continue;
                }

                else {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                    continue;
                }
            }
        }

        if (cabbages > 0) {
            while (cabbages > 0) {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickCabbages);
                while (pickCabbages < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                    printf("Pick some CABBAGES... how many did you pick? : ");
                    scanf("%d", &pickCabbages);
                }
                if (pickCabbages == cabbages) {
                    printf("Great, that's the cabbages done!\n\n");
                    cabbages = 0;
                }

                else if (pickCabbages < cabbages) {
                    printf("Looks like we still need some CABBAGES...\n");
                    cabbages -= pickCabbages;
                    continue;
                }

                else {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                    continue;
                }
            }
        }

        // Check if all items are picked
        if (apples == 0 && oranges == 0 && pears == 0 && tomatoes == 0 && cabbages == 0) {
            printf("All the items are picked!\n\n");
        }

        int doAnotherShopping;
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &doAnotherShopping);
        printf("\n");
        if (doAnotherShopping == 0) {
            shoppingDone = 1;
        }
    }
    
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}








