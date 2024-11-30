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
    int taskCompleted = 0;

    while (!taskCompleted) {
        printf("\nVyberte úkol:\n");
        switch (location) {
        case 1:
            printf("1. Překonejte bažinu (povinné - logická úloha)\n");
            printf("2. Nasbírejte dřevo (nepovinné - přidá předmět do inventáře)\n");
            printf("3. Najděte skrytý tábor (nepovinné - zvýší energii o 5)\n");
            break;
        case 2:
            printf("1. Vyřešte hádanku (povinné)\n");
            printf("2. Získejte léčivé byliny (nepovinné - přidá léčivou bylinu do inventáře)\n");
            printf("3. Vyhněte se pastím (nepovinné - zvýší mrštnost o 1)\n");
            break;
        case 3:
            printf("1. Porazte strážce (povinné - matematická úloha)\n");
            printf("2. Najděte tajnou chodbu (nepovinné - přidá drahokam do inventáře)\n");
            printf("3. Sesbírejte drahokamy (nepovinné - přidá drahokam do inventáře)\n");
            break;
        case 4:
            printf("1. Porazte draka (povinné - kombinace logické a matematické úlohy)\n");
            printf("2. Prohledejte dračí hnízdo (nepovinné - přidá tajný artefakt do inventáře)\n");
            printf("3. Otevřete tajnou truhlu (nepovinné - přidá zlatý poklad do inventáře)\n");
            break;
        }

        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup. Zadejte číslo úkolu.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        if (action == 1) {
            switch (location) {
            case 1: {
                printf("Bažina před vámi je nebezpečná. Vyřešte logickou úlohu, abyste mohli pokračovat dál.\n");
                printf("Otázka: Kolik nohou má pavouk? ");
                int answer1;
                if (scanf_s("%d", &answer1) != 1) {
                    printf("Neplatný vstup.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (answer1 == 8) {
                    printf("Správně! Podařilo se vám překonat bažinu.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Zkuste to znovu.\n");
                }
                break;
            }
            case 2: {
                printf("Hádanka: Co má zuby, ale nekouše? (odpověď zadejte bez diakritiky): ");
                char answer2[50];
                if (fgets(answer2, sizeof(answer2), stdin) == NULL) {
                    printf("Neplatný vstup.\n");
                    continue;
                }
                char* start = answer2;
                while (*start == ' ') start++;
                char* end = start + strlen(start) - 1;
                while (end > start && (*end == '\n' || *end == '\r' || *end == ' ')) end--;
                *(end + 1) = '\0';
                if (strcmp(start, "hreben") == 0) {
                    printf("Správně! Pokračujete dál.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Správná odpověď je 'hřeben'. Zkuste to znovu.\n");
                }
                break;
            }
            case 3: {
                printf("Matematická úloha: Kolik je 15 děleno 3? ");
                int answer3;
                if (scanf_s("%d", &answer3) != 1) {
                    printf("Neplatný vstup.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (answer3 == 5) {
                    printf("Správně! Porazili jste strážce.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Zkuste to znovu.\n");
                }
                break;
            }
            case 4: {
                printf("Poslední úkol: Vyřešte kombinaci. Kolik je 2 * 3 + 4? ");
                int answer4;
                if (scanf_s("%d", &answer4) != 1) {
                    printf("Neplatný vstup.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (answer4 == 10) {
                    printf("Správně! Porazili jste draka a dokončili hru.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Zkuste to znovu.\n");
                }
                break;
            }
            }
        }
        else if (action == 2) {
            switch (location) {
            case 1:
                printf("Nasbírali jste dřevo! Přidáno do inventáře.\n");
                addItemToInventory(&player->inventory, "Dřevo");
                break;
            case 2:
                printf("Získali jste léčivé byliny! Přidáno do inventáře.\n");
                addItemToInventory(&player->inventory, "Léčivá bylina");
                break;
            case 3:
                printf("Našli jste tajnou chodbu! Přidán drahokam do inventáře.\n");
                addItemToInventory(&player->inventory, "Drahokam");
                break;
            case 4:
                printf("Prohledali jste dračí hnízdo! Přidán tajný artefakt.\n");
                addItemToInventory(&player->inventory, "Tajný artefakt");
                break;
            }
        }
        else if (action == 3) {
            switch (location) {
            case 1:
                printf("Našli jste skrytý tábor! Zvýšena energie o 5.\n");
                player->energy += 5;
                break;
            case 2:
                printf("Úspěšně jste se vyhnuli pastím! Zvýšena mrštnost o 1.\n");
                player->agility += 1;
                break;
            case 3:
                printf("Sesbírali jste drahokamy! Přidán drahokam do inventáře.\n");
                addItemToInventory(&player->inventory, "Drahokam");
                break;
            case 4:
                printf("Otevřeli jste tajnou truhlu! Přidán zlatý poklad.\n");
                addItemToInventory(&player->inventory, "Zlatý poklad");
                break;
            }
        }
        else {
            printf("Neplatná volba. Zkuste to znovu.\n");
        }
    }

    printf("Všechny povinné úkoly v lokaci byly splněny! Pokračujete dál.\n");
}

#endif
