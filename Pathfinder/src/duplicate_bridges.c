#include "pathfinder.h"

static void mx_add(t_pars *stct, char *temp);
static int count_arr(char **arr);
static void mx_add1(t_pars *stct, char *temp);

void duplicate_bridges(char **file, t_pars *stct) {
    char **temp;
    char **temp1;
    
    stct->count_bridges = count_arr(file);
    stct->arr_count = 0;
    stct->arr_pars1 = (char**)malloc(((stct->count_bridges * 3) + 1) * sizeof(char*));
    for (int j = 0; j < ((stct->count_bridges * 3) + 1); j++)
        stct->arr_pars1[j] = NULL;
    for(int i = 1; file[i]; i++) {
        temp = mx_pars_str(file[i], i);
        mx_add(stct, temp[0]);
        mx_add(stct, temp[1]);
        mx_add(stct, temp[2]);
        mx_del_strarr(&temp);
    }
    stct->arr_bridges = (char**)malloc(((stct->count_bridges * 2) + 1) * sizeof(char*));
    stct->arr_count = 0;
    for (int k = 0; k < ((stct->count_bridges * 2) + 1); k++)
        stct->arr_bridges[k] = NULL;
    for (int g = 1; file[g]; g++) {
        temp1 = mx_pars_str(file[g], g);
        mx_add1(stct, temp1[0]);
        mx_add1(stct, temp1[1]);
        mx_del_strarr(&temp1);
    }
    error_dup1(stct);
}

static void mx_add(t_pars *stct, char *temp) {
    stct->arr_pars1[stct->arr_count] = mx_strdup(temp);
    stct->arr_count += 1;
}

static void mx_add1(t_pars *stct, char *temp) {
    stct->arr_bridges[stct->arr_count] = mx_strdup(temp);
    stct->arr_count += 1;
}

static int count_arr(char **arr) {
    int i = 1;

    while (arr[i] != NULL)
        i++;
    return (i - 1);
}
