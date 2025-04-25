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

    car.transmission.current_gear = 3;
    car.transmission.clutch_pressure = 70;

    car.battery.voltage = 12;
    car.battery.temperature = 30;

    car.fuel = 60;
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
    } else if (strcmp(param_name, "current_gear") == 0) {
        *value_out = car.transmission.current_gear;
    } else if (strcmp(param_name, "clutch_pressure") == 0) {
        *value_out = car.transmission.clutch_pressure;
    } else if (strcmp(param_name, "voltage") == 0) {
        *value_out = car.battery.voltage;
    } else if (strcmp(param_name, "battery_temp") == 0) {
        *value_out = car.battery.temperature;
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
    } else if (strcmp(param_name, "current_gear") == 0) {
        car.transmission.current_gear = new_value;
    } else if (strcmp(param_name, "clutch_pressure") == 0) {
        car.transmission.clutch_pressure = new_value;
    } else if (strcmp(param_name, "voltage") == 0) {
        car.battery.voltage = new_value;
    } else if (strcmp(param_name, "battery_temp") == 0) {
        car.battery.temperature = new_value;
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
    printf("  current_gear = %d\n", car.transmission.current_gear);
    printf("  clutch_pressure = %d\n", car.transmission.clutch_pressure);
    printf("  voltage = %d\n", car.battery.voltage);
    printf("  battery_temp = %d\n", car.battery.temperature);
}

void ecu_free() {
    // Rien à libérer pour l'instant, car Car est statique
}
