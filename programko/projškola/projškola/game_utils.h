#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void findNextPrimes(int number) {
    int count = 0;
    int candidate = number + 1;

    while (count < 3) {
        bool isPrime = true;
        for (int i = 2; i * i <= candidate; i++) {
            if (candidate % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", candidate);
            count++;
        }
        candidate++;
    }
    printf("\n");
}

#endif
