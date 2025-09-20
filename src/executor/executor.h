#ifndef MY_DATABASE_EXECUTOR_H
#define MY_DATABASE_EXECUTOR_H

#include "../include/types.h"
#include "../storage/disk.h"
#include <stdbool.h>

bool execute_command(DiskManager *dm, Command cmd);

#endif // MY_DATABASE_EXECUTOR_H