#include "pathfinder.h"

void file_is_empty(char *argv[]) {
    char buf;
    int a = open(argv[1], O_RDONLY);
    int s = read(a, &buf, 1);

    close(a);
    if (s <= 0 ) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
}
