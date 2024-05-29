#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {
    welcome();
    Player *player = init_character(); // Inicializamos al personaje
    printf("\n¡Bienvenido, %s!\n", player->name);

    printf("\n\nPrimer Nivel\n");
    Scenario *scenario = init_scenario();
    
    printf("\n\nSegundo Nivel\n");
    scenario = init_scenario2();

    printf("\n\nTercer Nivel\n");
    scenario = init_scenario3();

    printf("\n\nCuarto Nivel\n");
    scenario = init_scenario4();

    printf("\n\nUltimo Nivel\n");
    scenario = init_scenario5();
}