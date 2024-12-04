#ifndef LOCATION_H
#define LOCATION_H

#include <game_utils.h>
#include <character.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

void findNextThreePrimes(int start, int primes[3]) {
    int count = 0, num = start + 1;

    while (count < 3) {
        int isPrime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primes[count++] = num;
        }
        num++;
    }
}

void locationAction(int location, Character* player) {
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));

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
            printf("1. Překonejte bažinu (povinné)\n");
            printf("2. Nasbírejte dřevo (nepovinné)\n");
            printf("3. Najděte meč (nepovinné)\n");
            break;
        case 2:
            printf("1. Porazte nepřítele (povinné)\n");
            printf("2. Nasbírejte léčivé byliny (nepovinné)\n");
            printf("3. Najděte drahokam (nepovinné)\n");
            break;
        case 3:
            printf("1. Porazte strážce (povinné)\n");
            printf("2. Prozkoumejte chodbu (nepovinné)\n");
            printf("3. Najděte lektvar síly (nepovinné)\n");
            break;
        case 4:
            printf("1. Porazte draka (povinné)\n");
            printf("2. Prohledejte dračí hnízdo (nepovinné)\n");
            printf("3. Otevřete tajnou truhlu (nepovinné)\n");
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
                if (hasItem(&player->inventory, "Dřevo")) {
                    printf("Dřevo vám pomohlo postavit most a překonat bažinu snadno.\n");
                    taskCompleted = 1;
                    break;
                }
                printf("Nemáte dřevo. Musíte bažinu překonat sami.\n");
                printf("Otázka: Kolik noh má pavouk?\n");
                int answer1;
                if (scanf_s("%d", &answer1) == 1 && answer1 == 8) {
                    printf("Správně! Podařilo se vám překonat bažinu.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Zkuste to znovu.\n");
                }
                break;
            }
            case 2: {
                if (hasItem(&player->inventory, "Meč")) {
                    printf("Meč vám pomohl snadno porazit nepřítele!\n");
                    taskCompleted = 1;
                    break;
                }
                printf("Nemáte meč. Musíte nepřítele porazit sami.\n");
                printf("Otázka: Jaké je prvočíslo následující po 7?\n");
                int answer2;
                if (scanf_s("%d", &answer2) == 1 && answer2 == 11) {
                    printf("Správně! Porazili jste nepřítele.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Zkuste to znovu.\n");
                }
                break;
            }
            case 3: {
                if (hasItem(&player->inventory, "Lektvar síly")) {
                    printf("Lektvar síly vám dodal výhodu, snadno jste porazili strážce.\n");
                    taskCompleted = 1;
                    break;
                }
                printf("Nemáte lektvar síly. Musíte strážce porazit sami.\n");
                printf("Matematická úloha: Kolik je 24 děleno 6?\n");
                int answer3;
                if (scanf_s("%d", &answer3) == 1 && answer3 == 4) {
                    printf("Správně! Porazili jste strážce.\n");
                    taskCompleted = 1;
                }
                else {
                    printf("Špatná odpověď. Zkuste to znovu.\n");
                }
                break;
            }
            case 4: {
                if (hasItem(&player->inventory, "Meč")) {
                    printf("S pomocí meče jste snadno porazili draka!\n");
                    taskCompleted = 1;
                    break;
                }
                printf("Nemáte meč. Musíte draka porazit sami.\n");
                printf("Kombinovaná otázka: Kolik je 2 * 5 + 10?\n");
                int answer4;
                if (scanf_s("%d", &answer4) == 1 && answer4 == 20) {
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
        else if (action == 2 || action == 3) {
            switch (location) {
            case 1:
                if (action == 2) {
                    printf("Pro sběr dřeva odpovězte: Kolik je 3 + 3? ");
                    int woodAnswer;
                    if (scanf_s("%d", &woodAnswer) == 1 && woodAnswer == 6) {
                        printf("Správně! Nasbírali jste dřevo.\n");
                        addItemToInventory(&player->inventory, "Dřevo");
                    }
                    else {
                        printf("Špatná odpověď. Dřevo jste nenasbírali.\n");
                    }
                }
                else if (action == 3) {
                    printf("Pro získání meče musíte najít tři nejbližší prvočísla za náhodně generovaným číslem.\n");
                    int randomNum = rand() % 100 + 1;
                    printf("Číslo: %d\n", randomNum);

                    int primes[3];
                    findNextThreePrimes(randomNum, primes);

                    printf("Zadejte tři prvočísla oddělená mezerami: ");
                    int userAnswer1, userAnswer2, userAnswer3;
                    if (scanf_s("%d %d %d", &userAnswer1, &userAnswer2, &userAnswer3) == 3 &&
                        userAnswer1 == primes[0] && userAnswer2 == primes[1] && userAnswer3 == primes[2]) {
                        printf("Správně! Našli jste meč.\n");
                        addItemToInventory(&player->inventory, "Meč");
                    }
                    else {
                        printf("Špatná odpověď. Správná prvočísla jsou %d, %d, %d.\n", primes[0], primes[1], primes[2]);
                    }
                }
                break;

            case 2:
                if (action == 2) {
                    printf("Pro sběr bylin odpovězte: Kolik je 12 / 4? ");
                    int herbAnswer;
                    if (scanf_s("%d", &herbAnswer) == 1 && herbAnswer == 3) {
                        printf("Správně! Nasbírali jste léčivé byliny.\n");
                        addItemToInventory(&player->inventory, "Léčivé byliny");
                    }
                    else {
                        printf("Špatná odpověď. Byliny jste nenasbírali.\n");
                    }
                }
                else if (action == 3) {
                    printf("Pro získání drahokamu odpovězte: Kolik je 7 * 7? ");
                    int gemAnswer;
                    if (scanf_s("%d", &gemAnswer) == 1 && gemAnswer == 49) {
                        printf("Správně! Našli jste drahokam.\n");
                        addItemToInventory(&player->inventory, "Drahokam");
                    }
                    else {
                        printf("Špatná odpověď. Drahokam jste nenašli.\n");
                    }
                }
                break;

            case 3:
                if (action == 3) {
                    printf("Pro získání lektvaru síly odpovězte: Kolik je 15 + 10? ");
                    int potionAnswer;
                    if (scanf_s("%d", &potionAnswer) == 1 && potionAnswer == 25) {
                        printf("Správně! Našli jste lektvar síly.\n");
                        addItemToInventory(&player->inventory, "Lektvar síly");
                    }
                    else {
                        printf("Špatná odpověď. Lektvar síly jste nenašli.\n");
                    }
                }
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
