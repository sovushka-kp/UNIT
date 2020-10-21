#include "pathfinder.h"

static void for_err(t_pars *stct, int i);

void error_dup1(t_pars *stct) {
    int i;

    for (i = 0; stct->arr_bridges[i] && stct->arr_bridges[i + 2] != NULL 
        && stct->arr_bridges[i] != NULL; i++) {
        for_err(stct, i);
    }
}

static void for_err(t_pars *stct, int i) {
    for (int k = i + 2;  k < ((stct->count_bridges) * 2)
        && stct->arr_bridges[k] != NULL && stct->arr_bridges[k + 2] != NULL; k++) {
            if (i % 2 != 0) 
                i++;
            if (k % 2 != 0 || k == i)
                k++;
        if ((mx_strcmp(stct->arr_bridges[i], stct->arr_bridges[k]) == 0) && 
            (mx_strcmp(stct->arr_bridges[i + 1], stct ->arr_bridges[k + 1]) == 0)) {
            mx_printerr(DUPLICATE);
            mx_del_strarr(&stct->arr_pars1);
            mx_del_strarr(&stct->arr_pars);
            exit(1);
        }
        if ((mx_strcmp(stct->arr_bridges[i], stct->arr_bridges[k + 1]) == 0) && 
            (mx_strcmp(stct->arr_bridges[i + 1], stct ->arr_bridges[k]) == 0)) {
            mx_printerr(DUPLICATE);
            mx_del_strarr(&stct->arr_pars1);
            mx_del_strarr(&stct->arr_pars);
            exit(1);
       }
    }
}
