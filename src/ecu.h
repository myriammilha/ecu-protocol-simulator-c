#ifndef ECU_H
#define ECU_H

#define MAX_PARAMS 10
#define PARAM_NAME_LEN 32

typedef struct {
    char name[PARAM_NAME_LEN];
    int value;
} ECU_Param;

void ecu_init();
int ecu_read(const char *param_name, int *value_out);
int ecu_write(const char *param_name, int new_value);

#endif // ECU_H
