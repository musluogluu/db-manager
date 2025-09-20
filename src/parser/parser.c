#include "parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Command parse_command(const char *input) {
    Command cmd;
    cmd.type = CMD_UNKNOWN;

    char *input_copy = strdup(input);
    if (!input_copy) {
        return cmd;
    }

    char *token = strtok(input_copy, " ");

    if (token) {
        if (strcasecmp(token, "exit") == 0) {
            cmd.type = CMD_EXIT;
        } else if (strcasecmp(token, "insert") == 0) {
            cmd.type = CMD_INSERT;
            // id, name, age verilerini ayrıştır
            token = strtok(NULL, " ");
            if (token) cmd.user_data.id = atoi(token);
            token = strtok(NULL, " ");
            if (token) strncpy(cmd.user_data.name, token, sizeof(cmd.user_data.name) - 1);
            token = strtok(NULL, " ");
            if (token) cmd.user_data.age = atoi(token);
        } else if (strcasecmp(token, "select") == 0) {
            cmd.type = CMD_SELECT;
        }
    }

    free(input_copy);
    return cmd;
}