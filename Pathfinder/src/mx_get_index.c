#include "pathfinder.h"

int mx_get_index(t_pars *stct, char *c) {
    for (int i = 0; stct->arr_pars[i]; i++) {
        if (mx_strcmp(stct->arr_pars[i], c) == 0)
            return i;
    }
    return -1;
}
