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
    setlocale(LC_ALL, "");
    printf("\n--- Jste v lokaci: ");
    switch (location) {
    case 1: printf("Temný les ---\n"); break;
    case 2: printf("Ztracené údolí ---\n"); break;
    case 3: printf("Tajemná jeskyně ---\n"); break;
    case 4: printf("Dračí doupě ---\n"); break;
    default: printf("Neznámé místo ---\n"); break;
    }

    int action = 0;

    while (!(player->tasksCompleted[location - 1][0] &&
        player->tasksCompleted[location - 1][1])) {

        printf("Vyberte úkol:\n");
        switch (location) {
        case 1:
            printf("1. Nasbírejte dřevo (nepovinné)\n");
            printf("2. Překonejte bažinu (povinné)\n");
            printf("3. Najděte skrytý tábor (nepovinné)\n");
            break;
        case 2:
            printf("1. Získejte léčivé byliny (nepovinné)\n");
            printf("2. Vyřešte hádanku (povinné)\n");
            printf("3. Vyhněte se pastím (nepovinné)\n");
            break;
        case 3:
            printf("1. Najděte tajnou chodbu (nepovinné)\n");
            printf("2. Porazte strážce (povinné)\n");
            printf("3. Sesbírejte drahokamy (nepovinné)\n");
            break;
        case 4:
            printf("1. Prohledejte dračí hnízdo (nepovinné)\n");
            printf("2. Porazte draka (povinné)\n");
            printf("3. Otevřete tajnou truhlu (nepovinné)\n");
            break;
        }

        if (scanf("%d", &action) != 1) {
            printf("Neplatný vstup. Zadejte číslo úkolu.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (location) {
        case 2:
            if (action == 2 && !player->tasksCompleted[1][1]) {
                printf("Vyřešte hádanku: Co má zuby, ale nekouše? (Zadejte odpověď bez diakritiky)\n");
                char answer[50];
                fgets(answer, sizeof(answer), stdin);
                char* start = answer;
                while (*start == ' ') start++;
                char* end = start + strlen(start) - 1;
                while (end > start && (*end == '\n' || *end == '\r' || *end == ' ')) end--;
                *(end + 1) = '\0';
                for (int i = 0; start[i]; i++) {
                    start[i] = tolower(start[i]);
                }
                if (strcmp(start, "hreben") == 0) {
                    printf("Správně! Pokračujete dál.\n");
                    player->tasksCompleted[1][1] = 1;
                }
                else {
                    printf("Špatně. Správná odpověď je 'hreben'. Zkuste to znovu.\n");
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

    printf("Všechny povinné úkoly v lokaci byly splněny! Pokračujete dál.\n");
}

#endif
