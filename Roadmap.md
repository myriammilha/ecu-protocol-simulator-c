# 🛣️ Roadmap – ECU Communication Simulator

Ce document décrit les évolutions prévues pour enrichir le simulateur et passer à des fonctionnalités avancées en langage C.

---

## ✅ Version actuelle

- [x] Simulateur de communication entre outil de diagnostic et ECU
- [x] Commandes READ / WRITE / SHOW / EXIT
- [x] Gestion simple de paramètres (tableau fixe)
- [x] Test automatique via script bash
- [x] Projet structuré et documenté
- [x] Gestion dynamique de la mémoire
- [x] Pointeurs de fonction pour le protocole
- [x] Structures imbriquées

---

## 📈 Objectifs futurs

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
