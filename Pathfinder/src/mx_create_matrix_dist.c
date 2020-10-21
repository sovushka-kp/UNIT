#include "pathfinder.h"

void mx_create_matrix_dist(t_pars *stct) {
    int n = stct->count_island;

    stct->matrix_dist = NULL;
    stct->matrix_dist = (int **)malloc((n) * sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        stct->matrix_dist[i] = (int *)malloc(sizeof(int) * (n));
        for (int j = 0; j < n; j++) {
            stct->matrix_dist[i][j] = 0;
        }
    }
}
