#ifndef MY_DATABASE_TYPES_H
#define MY_DATABASE_TYPES_H

#include <stdint.h>
#include <stdbool.h>

// Temel veri tipleri
typedef uint32_t page_id_t;
typedef uint16_t db_size_t;

// Komut tipleri
typedef enum {
    CMD_EXIT,
    CMD_INSERT,
    CMD_SELECT,
    CMD_UNKNOWN
} CommandType;

// INSERT komutu için veri yapısı
typedef struct {
    uint32_t id;
    char name[256];
    uint32_t age;
} UserData;

// Yürütücüye gönderilecek komut yapısı
typedef struct {
    CommandType type;
    UserData user_data;
} Command;

#endif // MY_DATABASE_TYPES_H