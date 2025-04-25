#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "protocol.h"
#include "ecu.h"

typedef void (*CommandHandler)(const char *args);

typedef struct {
    const char *name;
    CommandHandler handler;
} Command;

void handle_read(const char *args);
void handle_write(const char *args);
void handle_show(const char *args);

Command commands[] = {
    { "READ", handle_read },
    { "WRITE", handle_write },
    { "SHOW", handle_show },
};

#define NUM_COMMANDS (sizeof(commands) / sizeof(Command))

void protocol_process_command(const char *cmd) {
    char command_name[16];
    char args[128];

    if (sscanf(cmd, "%15s %127[^\n]", command_name, args) < 1) {
        printf("Commande vide ou invalide.\n");
        return;
    }

    for (int i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            commands[i].handler(args);
            return;
        }
    }

    printf("Commande invalide. Syntaxe attendue :\n");
    printf("  READ <param>\n");
    printf("  WRITE <param> <valeur>\n");
    printf("  SHOW\n");
}

// === Command Handlers ===

void handle_read(const char *args) {
    int value;
    if (ecu_read(args, &value) == 0) {
        printf("%s = %d\n", args, value);
    } else {
        printf("Erreur : paramètre inconnu '%s'\n", args);
    }
}

void handle_write(const char *args) {
    char param_name[PARAM_NAME_LEN];
    int value;

    if (sscanf(args, "%31s %d", param_name, &value) == 2) {
        if (ecu_write(param_name, value) == 0) {
            printf("%s mis à jour à %d\n", param_name, value);
        } else {
            printf("Erreur : paramètre inconnu '%s'\n", param_name);
        }
    } else {
        printf("Syntaxe invalide. Utilisation : WRITE <param> <valeur>\n");
    }
}

void handle_show(const char *args) {
    (void)args; // SHOW n'a pas besoin d'arguments
    ecu_show_all();
}
