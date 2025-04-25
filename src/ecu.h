#ifndef ECU_H
#define ECU_H

#define PARAM_NAME_LEN 32

// Définition de la structure Engine
typedef struct {
    int speed;
    int rpm;
    int temp;
} Engine;

// Définition de la structure Car
typedef struct {
    Engine engine;
    int fuel;
    int gear;
} Car;

// Fonctions disponibles
void ecu_init();
int ecu_read(const char *param_name, int *value_out);
int ecu_write(const char *param_name, int new_value);
void ecu_show_all();
void ecu_free(); // Toujours là, même si plus vraiment utile pour l'instant

#endif // ECU_H
