#ifndef LOCATION_H
#define LOCATION_H

#include "game_utils.h"
#include "character.h"
#include <stdio.h>

void locationAction(int location, Character player) {
    printf("Jste v lokaci %d.\n", location);
    int action = 0;

    switch (location) {
    case 1:
        printf("1. Prohledej okolí\n");
        printf("2. Pokus se otevøít truhlu (uhodni kód)\n");
        printf("3. Pokraèuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 2) {
            int correctCode = generateRandomNumber(1, 10);

            if (player.intelligence > 7) {
                if (correctCode > 5) {
                    printf("Nápovìda: Možná byste se mìli zamìøit na vyšší èísla.\n");
                }
                else {
                    printf("Nápovìda: Možná byste se mìli zamìøit na nižší èísla.\n");
                }
            }

            printf("Zadejte èíslo mezi 1 a 10: ");
            int guess;
            if (scanf_s("%d", &guess) != 1) {
                printf("Neplatný vstup.\n");
                return;
            }
            if (guess == correctCode) {
                printf("Správný kód! Truhla se otevírá a nacházíte poklad.\n");
            }
            else {
                printf("Špatnì! Správný kód byl %d.\n", correctCode);
            }
        }
        break;

    case 2:
        printf("1. Projdi se po lese\n");
        printf("2. Vyøeš matematickou úlohu\n");
        printf("3. Pokraèuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 2) {
            printf("Doplòte chybìjící èíslo v øadì: 2, 4, 6, ?\n");

            if (player.intelligence > 6) {
                printf("Nápovìda: Hledejte pravidelnost ve zvìtšování èísel.\n");
            }

            int answer;
            if (scanf_s("%d", &answer) != 1) {
                printf("Neplatný vstup.\n");
                return;
            }
            if (answer == 8) {
                printf("Správnì! Pokraèujete dále.\n");
            }
            else {
                printf("Špatnì! Správná odpovìï byla 8.\n");
            }
        }
        break;

    case 3:
        printf("1. Bojuj s protivníkem\n");
        printf("2. Hledej zásoby\n");
        printf("3. Pokraèuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 1) {
            printf("Stisknìte enter pro hod kostkou...\n");
            getchar();
            getchar();

            srand((unsigned int)time(NULL));
            int roll = (rand() % 6) + 1;
            printf("Hodili jste: %d\n", roll);

            if (roll >= 4) {
                printf("Úder byl dostateènì silný a vyhrál jsi souboj!\n");
            }
            else {
                printf("Prohráváte souboj.\n");

                if (player.strength > 7) {
                    printf("Máte sílu vyšší než 7, získáváte druhý pokus!\n");
                    printf("Stisknìte enter pro nový hod kostkou...\n");
                    getchar();

                    roll = (rand() % 6) + 1;
                    printf("Hodili jste: %d\n", roll);

                    if (roll >= 4) {
                        printf("Úder byl dostateènì silný a vyhrál jsi souboj na druhý pokus!\n");
                    }
                    else {
                        printf("Prohráli jste souboj i na druhý pokus.\n");
                    }
                }
            }
        }
        break;

    case 4:
        printf("1. Najdi tajný vchod\n");
        printf("2. Vyøeš úlohu s prvoèísly\n");
        printf("3. Pokraèuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 2) {
            printf("Zadejte náhodnì generované èíslo: ");
            int number;
            if (scanf_s("%d", &number) != 1) {
                printf("Neplatný vstup.\n");
                return;
            }

            if (player.intelligence > 5) {
                printf("Nápovìda: Zkuste se zamìøit na èísla, která nejsou dìlitelná žádnými menšími èísly.\n");
            }

            printf("Nejbližší tøi prvoèísla po %d jsou: ", number);
            findNextPrimes(number);
        }
        break;

    default:
        printf("Pokraèujete do další lokace...\n");
        break;
    }
}

#endif
