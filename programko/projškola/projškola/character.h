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
    if (scanf("%s", player.name) != 1) {
        player.name[0] = '\0';
    }

    printf("Zvolte parametry vaší postavy (1-10):\n");

    do {
        printf("1. Síla: ");
        if (scanf("%d", &player.strength) != 1 || player.strength < 1 || player.strength > 10) {
            player.strength = 1;
        }
    } while (player.strength < 1 || player.strength > 10);

    do {
        printf("2. Inteligence: ");
        if (scanf("%d", &player.intelligence) != 1 || player.intelligence < 1 || player.intelligence > 10) {
            player.intelligence = 1;
        }
    } while (player.intelligence < 1 || player.intelligence > 10);

    do {
        printf("3. Mrštnost: ");
        if (scanf("%d", &player.agility) != 1 || player.agility < 1 || player.agility > 10) {
            player.agility = 1;
        }
    } while (player.agility < 1 || player.agility > 10);

    return player;
}

#endif
