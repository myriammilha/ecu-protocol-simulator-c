#include <stdio.h>
#include <string.h>
#include "ecu.h"
#include "protocol.h"

#define CMD_BUFFER_SIZE 128

int main() {
    char cmd_buffer[CMD_BUFFER_SIZE];

    ecu_init(); // Initialise les paramètres ECU

    printf("=== ECU Communication Simulator ===\n");
    printf("Tapez vos commandes (ex: READ speed, WRITE speed 50)\n");
    printf("Tapez EXIT pour quitter.\n\n");

    while (1) {
        printf("> ");
        if (fgets(cmd_buffer, CMD_BUFFER_SIZE, stdin) == NULL) {
            printf("Erreur de lecture de la commande.\n");
            continue;
        }

        // Retire le \n en fin de ligne
        cmd_buffer[strcspn(cmd_buffer, "\n")] = '\0';

        if (strcmp(cmd_buffer, "EXIT") == 0) {
            printf("Fermeture du simulateur.\n");
            break;
        }

        protocol_process_command(cmd_buffer);
    }
    ecu_free();
    return 0;
}
