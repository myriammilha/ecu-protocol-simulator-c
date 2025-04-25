#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "protocol.h"
#include "ecu.h"

void protocol_process_command(const char *cmd) {
    char param_name[PARAM_NAME_LEN];
    int value;

    // Essaye de parser une commande WRITE
    if (sscanf(cmd, "WRITE %31s %d", param_name, &value) == 2) {
        if (ecu_write(param_name, value) == 0) {
            printf("%s mis à jour à %d\n", param_name, value);
        } else {
            printf("Erreur : paramètre inconnu '%s'\n", param_name);
        }
        return;
    }

    // Essaye de parser une commande READ
    if (sscanf(cmd, "READ %31s", param_name) == 1) {
        if (ecu_read(param_name, &value) == 0) {
            printf("%s = %d\n", param_name, value);
        } else {
            printf("Erreur : paramètre inconnu '%s'\n", param_name);
        }
        return;
    }

    // Commande SHOW
    if (strcmp(cmd, "SHOW") == 0) {
        ecu_show_all();
        return;
    }


    // Si aucun des formats ne correspond
    printf("Commande invalide. Syntaxe attendue :\n");
    printf("  READ <param>\n");
    printf("  WRITE <param> <valeur>\n");
    printf("  SHOW\n");
}
