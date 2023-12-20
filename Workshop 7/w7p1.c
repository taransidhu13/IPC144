/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#define MAX_PATH_LENGTH 70
#define MAX_HISTORY_LENGTH MAX_PATH_LENGTH

typedef struct {
    int lives;
    char symbol;
    int treasureCount;
    int history[MAX_HISTORY_LENGTH];
} PlayerInfo;

typedef struct {
    int maxMoves;
    int pathLength;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
} GameInfo;


void configurePlayer(PlayerInfo* player) {
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player->symbol);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player->lives);

        if (player->lives < 1 || player->lives > 10) {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player->lives < 1 || player->lives > 10);

    player->treasureCount = 0;

    int i;
    for (i = 0; i < MAX_HISTORY_LENGTH; i++) {
        player->history[i] = 0;
    }

    printf("Player configuration set-up is complete\n");
}

void configureGame(GameInfo* game, const PlayerInfo* player) {
    printf("GAME Configuration\n");
    printf("------------------\n");

    int i;
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game->pathLength);

        if (game->pathLength < 10 || game->pathLength > 70 || game->pathLength % 5 != 0) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game->pathLength < 10 || game->pathLength > 70 || game->pathLength % 5 != 0);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game->maxMoves);

        int maxAllowedMoves = game->pathLength * 0.75;
        if (game->maxMoves < player->lives || game->maxMoves > maxAllowedMoves) {
            printf("    Value must be between %d and %d\n", player->lives, maxAllowedMoves);
        }
    } while (game->maxMoves < player->lives || game->maxMoves > game->pathLength * 0.75);


    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game->pathLength);

    for (i = 0; i < game->pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d",
            &game->bombs[i],
            &game->bombs[i + 1],
            &game->bombs[i + 2],
            &game->bombs[i + 3],
            &game->bombs[i + 4]);
    }


    printf("BOMB placement set\n");
    printf("\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game->pathLength);

    for (i = 0; i < game->pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d",
            &game->treasures[i],
            &game->treasures[i + 1],
            &game->treasures[i + 2],
            &game->treasures[i + 3],
            &game->treasures[i + 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");
}

void displaySummary(const PlayerInfo* player, const GameInfo* game) {
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player->symbol);
    printf("   Lives      : %d\n", player->lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game->pathLength);
    printf("   Bombs      : ");
    int i;
    for (i = 0; i < game->pathLength; i++) {
        printf("%d", game->bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game->pathLength; i++) {
        printf("%d", game->treasures[i]);
    }

    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

}
int move;

void printBoard(const PlayerInfo* player, const GameInfo* game) {
    int i;
    int mostRecentIndex = -1;
    printf("\n");
    printf("  ");
    

    // Find the index of the most recent move in player's history
    for (i = 0; i < game->pathLength; i++) {
        if (player->history[i]) {
            mostRecentIndex = i;
        }
    }

    // Print the ruler with symbol at the most recent position
    for (i = 0; i < game->pathLength; i++) {
        if (i == mostRecentIndex) {
            printf("%c", player->symbol);
        }
        else {
            printf(" ");
        }
    }
    
    printf("\n");
    printf("  ");
    for (i = 0; i < game->pathLength; i++) {
            if (player->history[i]) {
                if (game->bombs[i] && game->treasures[i]) {
                    printf("&");
                }
                else if (game->bombs[i]) {
                    printf("!");
                }
                else if (game->treasures[i]) {
                    printf("$");
                }
                else {
                    printf(".");
                }
            }
            else {
                printf("-");
            }
        }
        
    
    printf("\n");
    printf("  |||||||||1|||||||||2\n");
    printf("  12345678901234567890\n");
    printf("+---------------------------------------------------+\n");
    printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", player->lives, player->treasureCount, game->maxMoves);
    printf("+---------------------------------------------------+\n");
    
}

int main() {
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    PlayerInfo player;
    configurePlayer(&player);
    printf("\n");

    GameInfo game;
    configureGame(&game, &player);
    displaySummary(&player, &game);
    printBoard(&player, &game);

    while (player.lives > 0 && game.maxMoves > 0) {
        do {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &move);
            printf("\n");

            if (move < 1 || move > game.pathLength) {
                printf("  Out of Range!!!\n");
            }
            else if (player.history[move - 1] == 1) {
                printf("Dope! You've been here before!\n");
                move = 0;  // Set move to 0 to repeat the loop
            }
        } while (move < 1 || move > game.pathLength);

        player.history[move - 1] = 1;
        game.maxMoves--;

        if (game.bombs[move - 1] == 1) {
            player.lives--;
            if (game.treasures[move - 1] == 1) {
                player.treasureCount++;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            }
            else {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            }
        }
        else if (game.treasures[move - 1] == 1) {
            player.treasureCount++;
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
        }
        else {
            printf("===============> [.] ...Nothing found here... [.]");
        }
        printf("\n");
        
        printBoard(&player, &game);
    }
    
    printf("\n");
    printf("##################\n");
    printf("# Game over! #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}