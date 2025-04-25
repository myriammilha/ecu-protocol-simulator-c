#!/bin/bash

# Exécutable à tester
EXEC=./main

# Vérifie que l'exécutable existe
if [ ! -f "$EXEC" ]; then
    echo "Erreur : exécutable '$EXEC' introuvable. Compilez d'abord."
    exit 1
fi

# Commandes de test adaptées aux opcodes
cat << EOF | $EXEC
1 speed
2 speed 100
1 speed
1 rpm
2 rpm 4000
1 rpm
1 temp
1 fuel
2 current_gear 4
1 current_gear
3
EXIT
EOF