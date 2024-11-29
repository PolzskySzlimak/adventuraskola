#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "character.h"
#include "location.h"

#define MAX_LOCATION 5

int main() {
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));

    printf("Vítejte v čarovném lese!\n\n");
    Character player = createCharacter();

    printf("\nVítáme, %s! Vaše parametry jsou - Síla: %d, Inteligence: %d, Mrštnost: %d\n\n",
        player.name, player.strength, player.intelligence, player.agility);

    for (int i = 1; i <= MAX_LOCATION; i++) {
        locationAction(i, player);
    }

    printf("\nGratulujeme, %s! Úspěšně jste dokončili hru!\n", player.name);
    return 0;
}
