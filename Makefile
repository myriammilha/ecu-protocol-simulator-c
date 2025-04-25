# Nom de l'exécutable
TARGET = main

# Répertoires
SRC_DIR = src
OBJ_DIR = build

# Fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Fichiers objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Flags du compilateur
CFLAGS = -Wall -Wextra -I$(SRC_DIR)

# Compilateur
CC = gcc

# Règle par défaut
all: $(TARGET)

# Lien final
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compilation des .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier build si nécessaire
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Forçage de re-compilation
re: clean all