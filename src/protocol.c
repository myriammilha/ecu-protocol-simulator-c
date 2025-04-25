#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "protocol.h"
#include "ecu.h"

typedef void (*CommandHandler)(const char *args);

typedef struct {
    int opcode;
    CommandHandler handler;
} Command;

// Déclarations des fonctions handler
void handle_read(const char *args);
void handle_write(const char *args);
void handle_show(const char *args);

// Table des commandes avec codes numériques
Command commands[] = {
    { 1, handle_read },
    { 2, handle_write },
    { 3, handle_show },
};

#define NUM_COMMANDS (sizeof(commands) / sizeof(Command))

void protocol_process_command(const char *cmd) {
    int opcode;
    char args[128] = {0};

    if (sscanf(cmd, "%d %127[^\n]", &opcode, args) < 1) {
        printf("Commande vide ou invalide.\n");
        return;
    }

    for (size_t i = 0; i < NUM_COMMANDS; i++) {
        if (opcode == commands[i].opcode) {
            commands[i].handler(args);
            return;
        }
    }

    printf("Opcode inconnu. Opérations valides :\n");
    printf("  1 <param>            : READ param\n");
    printf("  2 <param> <value>    : WRITE param value\n");
    printf("  3                   : SHOW all parameters\n");
}

// === Fonctions handlers ===

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
        printf("Syntaxe invalide. Utilisation : 2 <param> <valeur>\n");
    }
}

void handle_show(const char *args) {
    (void)args; // SHOW n'a pas besoin d'arguments
    ecu_show_all();
}