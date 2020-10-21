//#include "../inc/pathfinder.h"
#include "pathfinder.h"

static int get_stack_index(t_backpath *stack);
static void push_to_stack(t_backpath *path_stack, int elem);
static int pop_from_stack(t_backpath *stack);
static bool check_next_pars(t_pars *stct, t_backpath *stack, int next_pars);

void mx_back_path(t_pars *stct, t_backpath *stack) {
    int a = stack->meme;
    
    if (get_stack_index(stack) == stack->path[0]) {
        mx_output(stct, stack);
        return;
    }
    else {
        for (int i = 0; i < a; i++) {
            if (check_next_pars(stct,stack, i)) {
                push_to_stack(stack,i);
                mx_back_path(stct,stack);
                pop_from_stack(stack);
            }
        }
    }
}

static int get_stack_index(t_backpath *stack) {
    return stack->path[stack->size];
}

static void push_to_stack(t_backpath *stack, int elem) {
    if (stack->size < stack->meme) {
        stack->size++;
        stack->path[stack->size] = elem;
    }
}

static int pop_from_stack(t_backpath *stack) {
    if (stack->size > 1) {
        stack->size--;
        return stack->path[stack->size + 1];
    }
    return stack->path[1];
}

static bool check_next_pars(t_pars *stct, t_backpath *stack, int next_pars) {
    int k = get_stack_index(stack);
    int j = stack->path[0];

    if (k != next_pars) {
        if (stct->matrix_floyd[k][next_pars] == stct->matrix_dist[j][k] - stct->matrix_dist[j][next_pars])
            return true;
    }
    return false;
}
