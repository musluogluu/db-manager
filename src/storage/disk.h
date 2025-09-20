#ifndef MY_DATABASE_DISK_H
#define MY_DATABASE_DISK_H

#include "../include/types.h"
#include "../include/constants.h"
#include <stdbool.h>

typedef struct {
    int file_descriptor;
} DiskManager;

bool open_database(DiskManager *dm, const char *path);
void close_database(DiskManager *dm);
bool read_page(DiskManager *dm, page_id_t page_id, char *data);
bool write_page(DiskManager *dm, page_id_t page_id, const char *data);

#endif // MY_DATABASE_DISK_H