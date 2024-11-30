#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}

#endif
