#ifndef LOCATION_H
#define LOCATION_H

#include "game_utils.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>

void locationAction(int location, Character player) {
    printf("\n--- Jste v lokaci %d ---\n", location);
    int action = 0;

    switch (location) {
    case 1:
        printf("1. Prohledejte okolí\n");
        printf("2. Pokuste se otevřít truhlu (uhodněte kód)\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 2) {
            int correctCode = generateRandomNumber(1, 10);
            printf("Zadejte číslo mezi 1 a 10: ");
            int guess;
            scanf("%d", &guess);
            if (guess == correctCode) {
                printf("Správný kód! Získáváte +1 sílu.\n");
                player.strength += 1;
            }
            else {
                printf("Špatně! Správný kód byl %d.\n", correctCode);
            }
        }
        break;

    case 2:
        printf("1. Projděte se po lese\n");
        printf("2. Vyřešte matematickou úlohu\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 2) {
            printf("Doplňte chybějící číslo v řadě: 2, 4, 6, ?\n");
            int answer;
            scanf("%d", &answer);
            if (answer == 8) {
                printf("Správně! Pokračujete dále.\n");
            }
            else {
                printf("Špatně! Správná odpověď byla 8.\n");
            }
        }
        break;

    case 3:
        printf("1. Bojujte s protivníkem\n");
        printf("2. Hledejte zásoby\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 1) {
            printf("Hod kostkou: ");
            int roll = generateRandomNumber(1, 6);
            printf("%d\n", roll);
            if (roll >= 4) {
                printf("Vyhráli jste boj!\n");
            }
            else {
                printf("Prohráli jste boj.\n");
            }
        }
        break;

    case 4:
        printf("1. Najděte tajný vchod\n");
        printf("2. Vyřešte úlohu s prvočísly\n");
        printf("3. Pokračujte dále\n");
        if (scanf("%d", &action) != 1) {
            return;
        }
        if (action == 2) {
            int number = generateRandomNumber(10, 100);
            printf("Vaše číslo: %d\n", number);
            findNextPrimes(number);
        }
        break;

    default:
        break;
    }
}

#endif
