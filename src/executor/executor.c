#include "executor.h"
#include <stdio.h>
#include <string.h>

bool execute_command(DiskManager *dm, Command cmd) {
    switch (cmd.type) {
        case CMD_INSERT: {
            printf("Veri ekleniyor: Id=%d, Name=%s, Age=%d\n",
                   cmd.user_data.id, cmd.user_data.name, cmd.user_data.age);
            
            char page_data[PAGE_SIZE] = {0};
            memcpy(page_data, &cmd.user_data, sizeof(UserData));

            write_page(dm, 0, page_data);
            break;
        }
        case CMD_SELECT: {
            printf("Veri okunuyor...\n");

            char page_data[PAGE_SIZE] = {0};
            read_page(dm, 0, page_data);

            UserData user_data;
            memcpy(&user_data, page_data, sizeof(UserData));
            
            printf("Id: %d, Name: %s, Age: %d\n", user_data.id, user_data.name, user_data.age);
            break;
        }
        default:
            printf("Bilinmeyen komut.\n");
            return false;
    }
    return true;
}