#include "pathfinder.h"

void invalid_usage(int argc) {
    if (argc != 2) {
        mx_printerr(INVALID_USAGE);
        exit(1);
    }
}
