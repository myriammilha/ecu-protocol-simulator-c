#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>        // close(), sleep()
#include <sys/types.h>     
#include <sys/socket.h>    
#include <netinet/in.h>    
#include <arpa/inet.h>     
#include <pthread.h>       // pour les threads

#include "ecu.h"
#include "protocol.h"

#define CMD_BUFFER_SIZE 128
#define PORT 12345
#define BACKLOG 5

// Déclaration de la tâche de fond
void *ecu_background_task(void *arg);

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char cmd_buffer[CMD_BUFFER_SIZE];

    ecu_init();

    // Démarrer le thread secondaire pour l'évolution des paramètres
    pthread_t background_thread;
    if (pthread_create(&background_thread, NULL, ecu_background_task, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // 1. Créer la socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 2. Attacher IP + PORT
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 3. Écouter les connexions
    if (listen(server_fd, BACKLOG) == -1) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("=== ECU Communication Simulator (TCP Server + Background Evolution) ===\n");
    printf("En attente de connexion sur le port %d...\n", PORT);

    // 4. Accepter une connexion
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if (client_fd == -1) {
        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connecté !\n");
    printf("Envoyez vos commandes via netcat. (Ex: 1 speed, 2 rpm 4000, 3)\n");
    printf("Tapez EXIT pour quitter.\n");

    // 5. Boucle principale de communication
    while (1) {
        memset(cmd_buffer, 0, sizeof(cmd_buffer));
        int received = recv(client_fd, cmd_buffer, sizeof(cmd_buffer) - 1, 0);
        if (received <= 0) {
            printf("Client déconnecté ou erreur.\n");
            break;
        }

        cmd_buffer[received] = '\0';

        // Vérifie si l'utilisateur veut quitter
        if (strcmp(cmd_buffer, "EXIT\n") == 0 || strcmp(cmd_buffer, "EXIT") == 0) {
            printf("Fermeture de la connexion.\n");
            break;
        }

        protocol_process_command(cmd_buffer);
    }

    // 6. Nettoyage
    close(client_fd);
    close(server_fd);
    ecu_free();

    return 0;
}

// === Tâche de fond pour faire évoluer les paramètres automatiquement ===
void *ecu_background_task(void *arg) {
    (void)arg; // pour éviter le warning unused

    while (1) {
        sleep(2);
        ecu_increase_temp();
        printf("[AUTO] Température moteur ajustée automatiquement.\n");
    }
    return NULL;
}

