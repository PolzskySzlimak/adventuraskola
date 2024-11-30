#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char items[10][50];
    int itemCount;
} Inventory;

void initializeInventory(Inventory* inventory) {
    inventory->itemCount = 0;
}

void addItemToInventory(Inventory* inventory, const char* item) {
    if (inventory->itemCount < 10) {
        strcpy(inventory->items[inventory->itemCount], item);
        inventory->itemCount++;
        printf("Přidáno do inventáře: %s\n", item);
    }
    else {
        printf("Inventář je plný!\n");
    }
}

int hasItem(Inventory* inventory, const char* item) {
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i], item) == 0) {
            return 1;
        }
    }
    return 0;
}

void useItem(Inventory* inventory, const char* item) {
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i], item) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {
                strcpy(inventory->items[j], inventory->items[j + 1]);
            }
            inventory->itemCount--;
            printf("Použito z inventáře: %s\n", item);
            return;
        }
    }
    printf("Předmět %s nebyl nalezen v inventáři.\n", item);
}

#endif
