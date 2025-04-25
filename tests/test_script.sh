#!/bin/bash

# Chemin vers l'exécutable
EXEC=./main

# Vérifie que le binaire existe
if [ ! -f "$EXEC" ]; then
    echo "Erreur : exécutable '$EXEC' introuvable. Compilez le projet d'abord."
    exit 1
fi

# Fichier temporaire contenant les commandes de test
TEST_CMDS=$(mktemp)

cat << EOF > "$TEST_CMDS"
READ speed
WRITE speed 100
READ speed
READ rpm
WRITE rpm 4000
READ fuel
READ gear
WRITE fuel 100
READ temp
WRITE temp 90
WRITE unknown_param 123
READ unknown_param
SHOW
EXIT
EOF

echo "=== Lancement du test automatique ==="
echo "Commandes utilisées :"
cat "$TEST_CMDS"
echo "========================"
echo ""

# Exécute le programme avec les commandes du script en entrée
"$EXEC" < "$TEST_CMDS"

# Nettoyage
rm "$TEST_CMDS"
