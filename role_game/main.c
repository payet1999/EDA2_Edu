#include <stdio.h>
#include "headers/game.h"

int main() {
    Character player;
    configureCharacter(&player);

    // Initialize scenes
    Scene scenes[4];
    initScenes(scenes);

    // Game loop
    int currentScene = 0;
    int result = 0;
    while (currentScene < 4) {  // NOTE: currentScene Nunca sera negativo
        result = playScene(&scenes[currentScene++], &player);
    }

    // NOTE: Ve ponindo ya comentarios de funcionalidad, que despues da pereza. Aqui seria rollo:
    // Evaluar si el usuario ha ganado o no en funcion de los puntos de vida
    if (player.hp > 0) {
        printf("Congratulations, you have completed the game!\n");
    } else {
        printf("Game over!\n");
    }

    return 0;
}
