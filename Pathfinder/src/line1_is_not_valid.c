#include "pathfinder.h"

void line1_is_not_valid(char *str) {
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!mx_isdigit(str[i])) {
            mx_printerr(LINE1_IS_NOT_VALID);
            exit(1);
        }
    }
} 
