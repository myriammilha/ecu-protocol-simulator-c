### 📄 `README.md`

```markdown
# 🚗 ECU Communication Simulator

Ce projet est un simulateur minimaliste en C d’une communication entre un outil de diagnostic et une ECU (unité de contrôle électronique).  
Il permet de **lire et écrire des paramètres** via des commandes textuelles simples.

---

## 🧠 Objectif

Simuler une ECU contenant quelques paramètres (`speed`, `rpm`,`temp`, `fuel`, `gear`) 
et communiquer avec elle via un protocole texte basique :
```
```bash
READ speed
WRITE speed 100
SHOW
```
---

## 📦 Structure du projet

```bash
ecu_comm_simulator/
│
├── src/                # Fichiers source C
│   ├── main.c
│   ├── ecu.c/.h        # Module ECU (stockage des paramètres)
│   └── protocol.c/.h   # Analyse et traitement des commandes
│
├── tests/
│   └── test_script.sh  # Script de test automatique
│
├── Makefile            # Compilation
└── README.md
```

---

## 🔧 Compilation

Assurez-vous d’avoir `gcc` installé.

```bash
make
```

Cela génère un exécutable `main`.

---

## 🚀 Utilisation

Lancez le simulateur :

```bash
./main
```

Tapez vos commandes :

```
> READ speed
speed = 45

> WRITE speed 100
speed mis à jour à 100

> READ speed
speed = 100

> SHOW
Liste des paramètres ECU :
  speed = 100
  rpm = 3000
```

Tapez `EXIT` pour quitter.

---

## 🧪 Tests automatiques

Lancez les tests avec :

```bash
chmod +x tests/test_script.sh
./tests/test_script.sh
```

---

## ⚙️ Commandes disponibles

- `READ <param>` – Affiche la valeur d’un paramètre
- `WRITE <param> <valeur>` – Modifie la valeur d’un paramètre
- `SHOW` – Affiche tous les paramètres actuels de l'ECU
- `EXIT` – Quitte le simulateur

---

## 📚 Exemple de session

```
> READ speed
speed = 45

> WRITE speed 80
speed mis à jour à 80

> READ rpm
rpm = 3000

> WRITE unknown_param 123
Erreur : paramètre inconnu 'unknown_param'
```

---

## ✍️ Auteur

Projet pédagogique réalisé pour apprendre :
- la structure d’un projet C
- la communication simulée machine-machine
- la modularité du code
- la gestion de tests simples en shell

Ce projet a été réalisé par **Myriam Milha**.

