#include "utils.h"
#include <string.h>

void print_error(const char *message) {
    if (message) {
        fprintf(stderr, "HATA: %s\n", message);
    }
    
    // errno değeri sıfır değilse, sistem hatası hakkında bilgi ekle
    if (errno) {
        fprintf(stderr, "Sistem hatası: %s\n", strerror(errno));
    }
}