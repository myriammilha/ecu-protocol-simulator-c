# 🛣️ Roadmap – ECU Communication Simulator

Ce document décrit les évolutions prévues pour enrichir le simulateur et passer à des fonctionnalités avancées en langage C.

---

## ✅ Version actuelle

- [x] Simulateur de communication entre outil de diagnostic et ECU
- [x] Commandes READ / WRITE / SHOW / EXIT
- [x] Gestion simple de paramètres (tableau fixe)
- [x] Test automatique via script bash
- [x] Projet structuré et documenté

---

## 📈 Objectifs futurs

### 🟦 1. Gestion dynamique de la mémoire
- Utiliser `malloc`/`free` pour stocker dynamiquement les paramètres
- Permettre l'ajout/suppression de paramètres au runtime

### 🟩 2. Pointeurs de fonction pour le protocole
- Associer chaque commande (`READ`, `WRITE`, `SHOW`) à une fonction
- Remplacer les `strcmp` par des appels dynamiques

### 🟨 3. Structures imbriquées
- Créer des structures hiérarchiques (`Engine`, `Transmission`, etc.)
- Améliorer la représentation logique des paramètres de l'ECU

### 🟧 4. Protocole binaire
- Supporter la communication en format binaire (0x01 READ, 0x02 WRITE)
- Conversion entre binaire et structure interne

### 🟥 5. Communication réseau avec Sockets
- Transformer l'ECU en serveur TCP
- Permettre à des clients externes de se connecter et envoyer des commandes

### 🟪 6. Gestion multithread
- Ajouter un thread pour simuler les évolutions naturelles de l'ECU (ex: température moteur qui monte)
- Synchronisation entre threads pour la lecture/écriture des paramètres

---

## ✍️ Auteur

Projet développé par **Myriam Milha** pour approfondir les compétences C embarqué et les protocoles de communication.

---

## 🎯 Objectif final

Créer un simulateur de communication ECU **professionnel** et **prêt pour l'industrie automobile**.
