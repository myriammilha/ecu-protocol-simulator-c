#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "protocol.h"
#include "ecu.h"

void protocol_process_command(const char *cmd) {
    char param_name[PARAM_NAME_LEN];
    int value;

    // WRITE command
    if (sscanf(cmd, "WRITE %31s %d", param_name, &value) == 2) {
        if (ecu_write(param_name, value) == 0) {
            printf("%s mis à jour à %d\n", param_name, value);
        } else {
            printf("Erreur : paramètre inconnu '%s'\n", param_name);
        }
        return;
    }

    // READ command
    if (sscanf(cmd, "READ %31s", param_name) == 1) {
        if (ecu_read(param_name, &value) == 0) {
            printf("%s = %d\n", param_name, value);
        } else {
            printf("Erreur : paramètre inconnu '%s'\n", param_name);
        }
        return;
    }

    // Commande invalide
    printf("Commande invalide. Syntaxe attendue :\n");
    printf("  READ <param>\n");
    printf("  WRITE <param> <valeur>\n");
}
