#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_pars *stct = malloc(sizeof(t_pars));
    stct->count_island = 0;
    int b;

    invalid_usage(argc);
    file_does_not_exist(argv);
    file_is_empty(argv);
    mx_parser(argv, stct);
    b = stct->count_island;
    mx_floyd(stct);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            if (i < j)
                mx_find_all_path(stct, i, j);
        }
    }
    return 0;
}
