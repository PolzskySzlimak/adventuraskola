#ifndef CHARACTER_H
#define CHARACTER_H

#include "inventory.h"

typedef struct {
    char name[50];
    int strength;
    int agility;
    int intelligence;
    int energy;
    Inventory inventory;
    int tasksCompleted[4][3];
} Character;

void initializeTasks(int tasksCompleted[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            tasksCompleted[i][j] = 0;
        }
    }
}

#endif
