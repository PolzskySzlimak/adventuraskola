#ifndef LOCATION_H
#define LOCATION_H

#include "game_utils.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void locationAction(int location, Character* player) {
    printf("\n--- Jste v lokaci %d ---\n", location);
    int action = 0;

    while (!(player->tasksCompleted[location - 1][0] &&
        player->tasksCompleted[location - 1][1] &&
        player->tasksCompleted[location - 1][2])) {

        printf("Vyberte úkol:\n");
        switch (location) {
        case 1:
            printf("1. Prohledejte okolí\n");
            printf("2. Otevřete truhlu\n");
            printf("3. Najděte stopy\n");
            break;
        case 2:
            printf("1. Nasbírejte byliny\n");
            printf("2. Vyřešte hádanku\n");
            printf("3. Překonejte pasti\n");
            break;
        case 3:
            printf("1. Bojujte s protivníkem\n");
            printf("2. Použijte zbraň\n");
            printf("3. Vyjednejte s protivníkem\n");
            break;
        case 4:
            printf("1. Odemkněte tajný vchod\n");
            printf("2. Vyřešte matematickou úlohu\n");
            printf("3. Najděte skrytý průchod\n");
            break;
        }

        if (scanf("%d", &action) != 1) {
            printf("Neplatný vstup. Zadejte číslo úkolu.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (location) {
        case 1:
            if (action == 1 && !player->tasksCompleted[0][0]) {
                printf("Prohledáváte okolí...\n");
                if (generateRandomNumber(1, 2) == 1) {
                    printf("Našli jste starou mapu!\n");
                    addItemToInventory(&player->inventory, "Stará mapa");
                }
                else {
                    printf("Nic jste nenašli, zkuste znovu.\n");
                }
                player->tasksCompleted[0][0] = 1;
            }
            else if (action == 2 && !player->tasksCompleted[0][1]) {
                printf("Otevíráte truhlu: Kolik je 5 + 3?\n");
                int answer;
                scanf("%d", &answer);
                if (answer == 8) {
                    printf("Správně! Našli jste klíč.\n");
                    addItemToInventory(&player->inventory, "Klíč");
                    player->tasksCompleted[0][1] = 1;
                }
                else {
                    printf("Špatně! Zkuste to znovu.\n");
                }
            }
            else if (action == 3 && !player->tasksCompleted[0][2]) {
                printf("Hledáte stopy...\n");
                if (generateRandomNumber(1, 2) == 1) {
                    printf("Našli jste stopy vedoucí do další oblasti.\n");
                    player->tasksCompleted[0][2] = 1;
                }
                else {
                    printf("Nic jste nenašli, zkuste to znovu.\n");
                }
            }
            else {
                printf("Tento úkol jste již splnili nebo zadání neplatí.\n");
            }
            break;

        case 2:
            if (action == 1 && !player->tasksCompleted[1][0]) {
                printf("Nasbíráte byliny...\n");
                addItemToInventory(&player->inventory, "Léčivá bylina");
                player->tasksCompleted[1][0] = 1;
            }
            else if (action == 2 && !player->tasksCompleted[1][1]) {
                printf("Vyřešte hádanku: Co má zuby, ale nekouše?\n");
                char answer[50];
                printf("Vaše odpověď: ");

                fgets(answer, sizeof(answer), stdin);

                char* start = answer;
                while (*start == ' ') start++;
                char* end = start + strlen(start) - 1;
                while (end > start && (*end == '\n' || *end == '\r' || *end == ' ')) end--;
                *(end + 1) = '\0';

                for (int i = 0; start[i]; i++) {
                    start[i] = tolower(start[i]);
                    if (start[i] == 'ř') start[i] = 'r';
                    if (start[i] == 'ě') start[i] = 'e';
                    if (start[i] == 'š') start[i] = 's';
                    if (start[i] == 'č') start[i] = 'c';
                    if (start[i] == 'ý') start[i] = 'y';
                    if (start[i] == 'á') start[i] = 'a';
                    if (start[i] == 'í') start[i] = 'i';
                    if (start[i] == 'é') start[i] = 'e';
                }

                if (strcmp(start, "hreben") == 0) {
                    printf("Správně! Pokračujete dál.\n");
                    player->tasksCompleted[1][1] = 1;
                }
                else {
                    printf("Špatně. Správná odpověď je 'hřeben'. Zkuste to znovu.\n");
                }
            }
            else if (action == 3 && !player->tasksCompleted[1][2]) {
                printf("Překonáváte pasti...\n");
                if (player->agility > 5) {
                    printf("Podařilo se! Pokračujete dál.\n");
                    player->tasksCompleted[1][2] = 1;
                }
                else {
                    printf("Past vás zdržela. Zkuste něco jiného.\n");
                }
            }
            else {
                printf("Tento úkol jste již splnili nebo zadání neplatí.\n");
            }
            break;

        case 3:
            if (action == 1 && !player->tasksCompleted[2][0]) {
                printf("Bojujete s protivníkem...\n");
                int roll = generateRandomNumber(1, 6);
                printf("Hod kostkou: %d\n", roll);
                if (roll >= 4) {
                    printf("Porazili jste protivníka!\n");
                    player->tasksCompleted[2][0] = 1;
                }
                else {
                    printf("Prohráli jste boj. Zkuste to znovu.\n");
                }
            }
            else if (action == 2 && !player->tasksCompleted[2][1]) {
                printf("Používáte zbraň...\n");
                if (hasItem(player->inventory, "Meč")) {
                    printf("Mečem porážíte protivníka!\n");
                    useItem(&player->inventory, "Meč");
                    player->tasksCompleted[2][1] = 1;
                }
                else {
                    printf("Nemáte vhodnou zbraň.\n");
                }
            }
            else if (action == 3 && !player->tasksCompleted[2][2]) {
                printf("Pokoušíte se vyjednat...\n");
                if (player->intelligence > 6) {
                    printf("Vyjednali jste mír! Pokračujete dál.\n");
                    player->tasksCompleted[2][2] = 1;
                }
                else {
                    printf("Vyjednávání selhalo. Zkuste jiný úkol.\n");
                }
            }
            else {
                printf("Tento úkol jste již splnili nebo zadání neplatí.\n");
            }
            break;

        case 4:
            if (action == 1 && !player->tasksCompleted[3][0]) {
                printf("Odemykáte tajný vchod...\n");
                if (hasItem(player->inventory, "Klíč")) {
                    printf("Použili jste klíč a odemkli tajný vchod!\n");
                    useItem(&player->inventory, "Klíč");
                    player->tasksCompleted[3][0] = 1;
                }
                else {
                    printf("Nemáte klíč.\n");
                }
            }
            else if (action == 2 && !player->tasksCompleted[3][1]) {
                printf("Vyřešte úlohu: Kolik je 9 * 3?\n");
                int answer;
                scanf("%d", &answer);
                if (answer == 27) {
                    printf("Správně! Pokračujete dál.\n");
                    player->tasksCompleted[3][1] = 1;
                }
                else {
                    printf("Špatně. Zkuste to znovu.\n");
                }
            }
            else if (action == 3 && !player->tasksCompleted[3][2]) {
                printf("Hledáte skrytý průchod...\n");
                if (hasItem(player->inventory, "Stará mapa")) {
                    printf("Díky mapě jste našli skrytý průchod!\n");
                    useItem(&player->inventory, "Stará mapa");
                    player->tasksCompleted[3][2] = 1;
                }
                else {
                    printf("Nemáte mapu. Zkuste něco jiného.\n");
                }
            }
            else {
                printf("Tento úkol jste již splnili nebo zadání neplatí.\n");
            }
            break;

        default:
            printf("Neplatná volba.\n");
            break;
        }
    }

    printf("Všechny úkoly v lokaci %d byly splněny! Pokračujete dál.\n", location);
}

#endif
