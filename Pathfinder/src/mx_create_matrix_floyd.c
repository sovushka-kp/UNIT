#include "pathfinder.h"

void mx_create_matrix_floyd(t_pars *stct) {
    int n = stct->count_island;

    stct->matrix_floyd = NULL;
    stct->matrix_floyd = (int **)malloc((n) * sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        stct->matrix_floyd[i] = (int *)malloc(sizeof(int) * (n));
        for (int j = 0; j < n; j++) {
            stct->matrix_floyd[i][j] = stct->matrix_dist[i][j];
        }
    }
}
