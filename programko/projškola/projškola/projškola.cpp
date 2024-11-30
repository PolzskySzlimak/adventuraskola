#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "character.h"
#include "location.h"
#include <string.h>
#include <ctype.h>

#define MAX_LOCATION 4

void printGratulace(char* name) {
    int nameLength = strlen(name);
    char lastChar = tolower(name[nameLength - 1]);

    if (lastChar == 'a') {
        printf("\nGratulujeme, %s! Úspěšně jste dokončila hru!\n", name);
    }
    else {
        char modifiedName[MAX_NAME_LENGTH];
        strcpy(modifiedName, name);

        if (lastChar == 'e' || lastChar == 'i' || lastChar == 'y') {
            printf("\nGratulujeme, %s! Úspěšně jste dokončil hru!\n", name);
        }
        else {
            if (nameLength > 1) {
                modifiedName[nameLength - 1] = 'e';
            }
            else {
                strcat(modifiedName, "e");
            }
            printf("\nGratulujeme, %s! Úspěšně jste dokončil hru!\n", modifiedName);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));

    printf("Vítejte v textové hře - adventura!\n\n");
    Character player = createCharacter();

    printf("\nVítáme vás, %s! Vaše parametry jsou - Síla: %d, Inteligence: %d, Mrštnost: %d\n\n",
        player.name, player.strength, player.intelligence, player.agility);

    for (int i = 1; i <= MAX_LOCATION; i++) {
        locationAction(i, player);
    }

    printGratulace(player.name);
    return 0;
}
