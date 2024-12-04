#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <character.h<
#include <game_utils.h>
#include <location.h>

void assignAttributes(Character* player) {
    int points = 15;
    printf("Máte %d bodů, které můžete rozdělit mezi své atributy (síla, inteligence, mrštnost).\n", points);

    while (points > 0) {
        printf("Kolik bodů chcete přiřadit síle? (Aktuálně: %d bodů)\n", points);
        scanf("%d", &player->strength);
        if (player->strength > points || player->strength < 0) {
            printf("Neplatná hodnota. Zadejte číslo v rozsahu 0 až %d.\n", points);
            continue;
        }

        points -= player->strength;

        printf("Kolik bodů chcete přiřadit inteligenci? (Zbývá: %d bodů)\n", points);
        scanf("%d", &player->intelligence);
        if (player->intelligence > points || player->intelligence < 0) {
            printf("Neplatná hodnota. Zadejte číslo v rozsahu 0 až %d.\n", points);
            continue;
        }

        points -= player->intelligence;

        printf("Kolik bodů chcete přiřadit mrštnosti? (Zbývá: %d bodů)\n", points);
        player->agility = points;
        if (player->agility < 0) {
            printf("Neplatná hodnota. Zadejte číslo v rozsahu 0 až %d.\n", points);
            continue;
        }

        points = 0; 
    }

    printf("\nVaše atributy:\nSíla: %d\nInteligence: %d\nMrštnost: %d\n", player->strength, player->intelligence, player->agility);
}

int main() {
    setlocale(LC_ALL, "");

    Character player;

    printf("Vítejte ve hře! Jak se jmenujete?\n");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = '\0';

    initializeInventory(&player.inventory);
    initializeTasks(player.tasksCompleted);

    assignAttributes(&player);

    player.energy = 20;

    printf("\nDobrodružství začíná, %s! Vaše cesta je plná výzev...\n", player.name);

    for (int i = 1; i <= 4; i++) {
        locationAction(i, &player);
    }

    printf("\nGratulujeme, %s! Dokončili jste všechny lokace a zvítězili jste ve hře!\n", player.name);
    return 0;
}
