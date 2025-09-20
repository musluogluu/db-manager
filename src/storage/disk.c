#include "disk.h"
#include "../common/utils.h" // Yeni eklenen başlık
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

bool open_database(DiskManager *dm, const char *path) {
    dm->file_descriptor = open(path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (dm->file_descriptor == -1) {
        print_error("Veritabanı dosyası açılamadı."); // perror() yerine
        return false;
    }

    return true;
}

void close_database(DiskManager *dm) {
    if (dm->file_descriptor != -1) {
        close(dm->file_descriptor);
        dm->file_descriptor = -1;
    }
}

bool read_page(DiskManager *dm, page_id_t page_id, char *data) {
    off_t offset = (off_t)page_id * PAGE_SIZE;

    if (lseek(dm->file_descriptor, offset, SEEK_SET) == -1) {
        print_error("Dosya konumu ayarlanamadı."); // perror() yerine
        return false;
    }

    if (read(dm->file_descriptor, data, PAGE_SIZE) == -1) {
        print_error("Diskten okuma hatası."); // perror() yerine
        return false;
    }

    return true;
}

bool write_page(DiskManager *dm, page_id_t page_id, const char *data) {
    off_t offset = (off_t)page_id * PAGE_SIZE;

    if (lseek(dm->file_descriptor, offset, SEEK_SET) == -1) {
        print_error("Dosya konumu ayarlanamadı."); // perror() yerine
        return false;
    }

    if (write(dm->file_descriptor, data, PAGE_SIZE) == -1) {
        print_error("Diske yazma hatası."); // perror() yerine
        return false;
    }

    return true;
}