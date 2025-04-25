#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ecu.h"

// Objet global représentant l'ECU
static Car car;

void ecu_init() {
    car.engine.speed = 45;
    car.engine.rpm = 3000;
    car.engine.temp = 90;
    car.fuel = 60;
    car.gear = 3;
}

int ecu_read(const char *param_name, int *value_out) {
    if (strcmp(param_name, "speed") == 0) {
        *value_out = car.engine.speed;
    } else if (strcmp(param_name, "rpm") == 0) {
        *value_out = car.engine.rpm;
    } else if (strcmp(param_name, "temp") == 0) {
        *value_out = car.engine.temp;
    } else if (strcmp(param_name, "fuel") == 0) {
        *value_out = car.fuel;
    } else if (strcmp(param_name, "gear") == 0) {
        *value_out = car.gear;
    } else {
        return -1;
    }
    return 0;
}

int ecu_write(const char *param_name, int new_value) {
    if (strcmp(param_name, "speed") == 0) {
        car.engine.speed = new_value;
    } else if (strcmp(param_name, "rpm") == 0) {
        car.engine.rpm = new_value;
    } else if (strcmp(param_name, "temp") == 0) {
        car.engine.temp = new_value;
    } else if (strcmp(param_name, "fuel") == 0) {
        car.fuel = new_value;
    } else if (strcmp(param_name, "gear") == 0) {
        car.gear = new_value;
    } else {
        return -1;
    }
    return 0;
}

void ecu_show_all() {
    printf("Liste des paramètres ECU :\n");
    printf("  speed = %d\n", car.engine.speed);
    printf("  rpm = %d\n", car.engine.rpm);
    printf("  temp = %d\n", car.engine.temp);
    printf("  fuel = %d\n", car.fuel);
    printf("  gear = %d\n", car.gear);
}

void ecu_free() {
    // Rien à libérer pour l'instant, car car est statique
}
