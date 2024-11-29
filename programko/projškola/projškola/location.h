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
        printf("2. Pokus se otevřít truhlu (uhodni kód)\n");
        printf("3. Pokračuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 2) {
            int correctCode = generateRandomNumber(1, 10);

            if (player.intelligence > 7) {
                if (correctCode > 5) {
                    printf("Nápověda: Možná byste se měli zaměřit na vyšší čísla.\n");
                }
                else {
                    printf("Nápověda: Možná byste se měli zaměřit na nižší čísla.\n");
                }
            }

            printf("Zadejte číslo mezi 1 a 10: ");
            int guess;
            if (scanf_s("%d", &guess) != 1) {
                printf("Neplatný vstup.\n");
                return;
            }
            if (guess == correctCode) {
                printf("Správný kód! Truhla se otevírá a nacházíte poklad.\n");
            }
            else {
                printf("Špatně! Správný kód byl %d.\n", correctCode);
            }
        }
        break;

    case 2:
        printf("1. Projdi se po lese\n");
        printf("2. Vyřeš matematickou úlohu\n");
        printf("3. Pokračuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 2) {
            printf("Doplňte chybějící číslo v řadě: 2, 4, 6, ?\n");

            if (player.intelligence > 6) {
                printf("Nápověda: Hledejte pravidelnost ve zvětšování čísel.\n");
            }

            int answer;
            if (scanf_s("%d", &answer) != 1) {
                printf("Neplatný vstup.\n");
                return;
            }
            if (answer == 8) {
                printf("Správně! Pokračujete dále.\n");
            }
            else {
                printf("Špatně! Správná odpověď byla 8.\n");
            }
        }
        break;

    case 3:
        printf("1. Bojuj s protivníkem\n");
        printf("2. Hledej zásoby\n");
        printf("3. Pokračuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 1) {
            printf("Stiskněte enter pro hod kostkou...\n");
            getchar();
            getchar();

            srand((unsigned int)time(NULL));
            int roll = (rand() % 6) + 1;
            printf("Hodili jste: %d\n", roll);

            if (roll >= 4) {
                printf("Úder byl dostatečně silný a vyhrál jsi souboj!\n");
            }
            else {
                printf("Prohráváte souboj.\n");

                if (player.strength > 7) {
                    printf("Máte sílu větší než 7, získáváte druhý pokus!\n");
                    printf("Stiskněte enter pro nový hod kostkou...\n");
                    getchar();

                    roll = (rand() % 6) + 1;
                    printf("Hodili jste: %d\n", roll);

                    if (roll >= 4) {
                        printf("Úder byl dostatečně silný a vyhrál jsi souboj na druhý pokus!\n");
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
        printf("2. Vyřeš úlohu s prvočísly\n");
        printf("3. Pokračuj dále\n");
        if (scanf_s("%d", &action) != 1) {
            printf("Neplatný vstup.\n");
            return;
        }

        if (action == 2) {
            printf("Zadejte náhodně generované číslo: ");
            int number;
            if (scanf_s("%d", &number) != 1) {
                printf("Neplatný vstup.\n");
                return;
            }

            if (player.intelligence > 5) {
                printf("Nápověda: Zkuste se zaměřit na čísla, která nejsou dělitelná žádnými menšími čísly.\n");
            }

            printf("Nejbližší tři prvočísla po %d jsou: ", number);
            findNextPrimes(number);
        }
        break;

    default:
        printf("Pokračujete do další lokace...\n");
        break;
    }
}

#endif
