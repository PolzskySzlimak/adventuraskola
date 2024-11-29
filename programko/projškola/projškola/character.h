#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int strength;
    int intelligence;
    int agility;
} Character;

Character createCharacter() {
    Character player;
    printf("Zadejte jméno vaší postavy: ");
    if (scanf_s("%s", player.name, (unsigned)_countof(player.name)) != 1) {
        printf("Chyba pøi ètení jména.\n");
        player.name[0] = '\0';
    }

    printf("Zvolte parametry vaší postavy:\n");
    printf("1. Síla (1 - 10): ");
    if (scanf_s("%d", &player.strength) != 1) {
        player.strength = 1;
    }
    printf("2. Inteligence (1 - 10): ");
    if (scanf_s("%d", &player.intelligence) != 1) {
        player.intelligence = 1;
    }
    printf("3. Mrštnost (1 - 10): ");
    if (scanf_s("%d", &player.agility) != 1) {
        player.agility = 1;
    }

    return player;
}

#endif
