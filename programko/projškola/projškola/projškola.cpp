#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "character.h"
#include "game_utils.h"
#include "location.h"

int main() {
    setlocale(LC_ALL, "");

    Character player;

    printf("Vítejte ve hře! Jak se jmenujete?\n");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = '\0';

    player.strength = 5;
    player.agility = 5;
    player.intelligence = 5;
    player.energy = 20;
    initializeInventory(&player.inventory);
    initializeTasks(player.tasksCompleted);

    printf("Vítejte, %s! Vaše dobrodružství začíná...\n", player.name);

    for (int i = 1; i <= 4; i++) {
        locationAction(i, &player);
    }

    printf("\nGratulujeme, %s! Dokončili jste všechny lokace a zvítězili jste ve hře!\n", player.name);
    return 0;
}
