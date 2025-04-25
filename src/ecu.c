#include <stdio.h>
#include <string.h>
#include "ecu.h"

static ECU_Param params[MAX_PARAMS];
static int param_count = 0;

static int find_param_index(const char *name) {
    for (int i = 0; i < param_count; i++) {
        if (strcmp(params[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void ecu_init() {
    strcpy(params[0].name, "speed");
    params[0].value = 45;

    strcpy(params[1].name, "rpm");
    params[1].value = 3000;

    param_count = 2;
}

int ecu_read(const char *param_name, int *value_out) {
    int index = find_param_index(param_name);
    if (index == -1) return -1;
    *value_out = params[index].value;
    return 0;
}

int ecu_write(const char *param_name, int new_value) {
    int index = find_param_index(param_name);
    if (index == -1) return -1;
    params[index].value = new_value;
    return 0;
}
