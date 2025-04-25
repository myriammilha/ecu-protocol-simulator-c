# ecu-protocol-simulator-c
Simulateur minimaliste en C d’une communication entre un outil de diagnostic et une ECU (unité de contrôle électronique / embarquée). 

### 💡 Compile directement avec `gcc` :

```bash
gcc -Wall -Wextra -Isrc -o main src/main.c src/ecu.c src/protocol.c
```

Puis exécute :

```bash
./main
```