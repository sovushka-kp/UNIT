#include "pathfinder.h"

void file_does_not_exist(char *argv[]) {
    char *file = argv[1];
    int open_f = open(file, O_RDONLY);

    if (open_f < 0) {
        close(open_f);
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    close(open_f);
}
