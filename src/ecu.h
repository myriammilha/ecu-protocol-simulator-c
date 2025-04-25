#ifndef ECU_H
#define ECU_H

#define PARAM_NAME_LEN 32

typedef struct {
    int voltage;  // Tension batterie (ex: 12V)
    int temperature; // Température batterie
} Battery;

typedef struct {
    int current_gear;
    int clutch_pressure;
} Transmission;

// Définition de la structure Engine
typedef struct {
    int speed;
    int rpm;
    int temp;
} Engine;

// Définition de la structure Car
typedef struct {
    Engine engine;
    Transmission transmission;
    Battery battery;
    int fuel;
} Car;

// Fonctions disponibles
void ecu_init();
int ecu_read(const char *param_name, int *value_out);
int ecu_write(const char *param_name, int new_value);
void ecu_show_all();
void ecu_free(); // Toujours là, même si plus vraiment utile pour l'instant
void ecu_increase_temp();

#endif // ECU_H
