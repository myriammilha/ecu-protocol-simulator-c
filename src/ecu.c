#include <stdio.h>
#include <string.h>
#include "ecu.h"

// Paramètres internes simulés (statiques)
static ECU_Param params[MAX_PARAMS];
static int param_count = 0;

// Fonction utilitaire : recherche d’un paramètre par nom
static int find_param_index(const char *name) {
    for (int i = 0; i < param_count; i++) {
        if (strcmp(params[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Initialisation avec des paramètres par défaut
void ecu_init() {
    // Paramètre 1 : speed = Vitesse du véhicule (en km/h)
    strcpy(params[0].name, "speed");
    params[0].value = 45;

    // Paramètre 2 : rpm = Régime moteur (en tours/minute)
    strcpy(params[1].name, "rpm");
    params[1].value = 3000;

    param_count = 2;
}

// Lecture d’un paramètre
int ecu_read(const char *param_name, int *value_out) {
    int index = find_param_index(param_name);
    if (index == -1) {
        return -1;
    }
    *value_out = params[index].value;
    return 0;
}

// Écriture d’un paramètre
int ecu_write(const char *param_name, int new_value) {
    int index = find_param_index(param_name);
    if (index == -1) {
        return -1;
    }
    params[index].value = new_value;
    return 0;
}

// Affichage des paramètres
void ecu_show_all() {
    printf("Liste des paramètres ECU :\n");
    for (int i = 0; i < param_count; i++) {
        printf("  %s = %d\n", params[i].name, params[i].value);
    }
}

