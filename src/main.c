#include <stdio.h>
#include <string.h>

#include "storage/disk.h"
#include "parser/parser.h"
#include "executor/executor.h"

int main() {
    DiskManager dm;
    char *db_path = "data/my_db.db";

    if (!open_database(&dm, db_path)) {
        return 1;
    }

    printf("Veritabanı motoru başlatıldı. Çıkmak için 'exit' yazın.\n");
    printf("Örnek komut: insert 1 Ahmet 30\n");
    printf("Örnek komut: select\n");

    char input_buffer[1024];

    while (1) {
        printf("> ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            break;
        }

        // Yeni satır karakterini kaldır
        input_buffer[strcspn(input_buffer, "\n")] = 0;

        if (strlen(input_buffer) == 0) {
            continue;
        }

        Command cmd = parse_command(input_buffer);

        if (cmd.type == CMD_EXIT) {
            break;
        }

        execute_command(&dm, cmd);
    }

    close_database(&dm);
    printf("Veritabanı kapatıldı. Güle güle!\n");

    return 0;
}