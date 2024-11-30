#ifndef LOCATION_H
#define LOCATION_H

#include "game_utils.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>

void locationAction(int location, Character *player) {
    printf("\n--- Jste v lokaci %d ---\n", location);
    int action = 0;

    switch (location) {
    case 1:
        printf("1. Prohledejte okolí\n");
        printf("2. Otevřete truhlu\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 2) {
            printf("Otevíráte truhlu...\n");
            addItemToInventory(&player->inventory, "Klíč");
        }
        break;

    case 2:
        printf("1. Hledejte zásoby\n");
        printf("2. Vyřešte matematickou úlohu\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }
        if (action == 1) {
            printf("Našli jste lektvar síly!\n");
            addItemToInventory(&player->inventory, "Lektvar síly");
        } else if (action == 2) {
            printf("Doplňte chybějící číslo v řadě: 2, 4, 6, ?\n");
            int answer;
            if (scanf("%d", &answer) != 1) {
                printf("Neplatný vstup. Odpověď musí být číslo.\n");
                return;
            }
            if (answer == 8) {
                printf("Správně! Získali jste +1 inteligenci.\n");
                player->intelligence += 1;
            } else {
                printf("Špatně! Správná odpověď byla 8.\n");
            }
        }
        break;

    case 3:
        printf("1. Bojujte s protivníkem\n");
        printf("2. Hledejte zásoby\n");
        printf("3. Použijte předmět z inventáře\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 1) {
            int roll = generateRandomNumber(1, 6);
            printf("Hod kostkou: %d\n", roll);
            if (roll >= 4) {
                printf("Porazili jste protivníka!\n");
            } else {
                printf("Prohráli jste boj.\n");
            }
        } else if (action == 3) {
            showInventory(player->inventory);
            printf("Zadejte název předmětu, který chcete použít: ");
            char item[MAX_NAME_LENGTH];
            scanf("%s", item);
            if (strcmp(item, "Meč") == 0 && hasItem(player->inventory, "Meč")) {
                printf("Používáte meč a porážíte protivníka!\n");
                useItem(&player->inventory, "Meč");
            } else if (strcmp(item, "Lektvar síly") == 0 && hasItem(player->inventory, "Lektvar síly")) {
                printf("Vypili jste lektvar a získali +2 sílu!\n");
                player->strength += 2;
                useItem(&player->inventory, "Lektvar síly");
            } else {
                printf("Nemáte tento předmět v inventáři.\n");
            }
        }
        break;

    case 4:
        printf("1. Pokuste se odemknout tajný vchod\n");
        printf("2. Hledejte další zásoby\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 1) {
            if (hasItem(player->inventory, "Klíč")) {
                printf("Použili jste klíč a odemkli tajný vchod!\n");
                useItem(&player->inventory, "Klíč");
            } else {
                printf("Nemáte klíč. Hledejte ho v předchozích lokacích.\n");
            }
        }
        break;

    default:
        break;
    }
}

#endif
