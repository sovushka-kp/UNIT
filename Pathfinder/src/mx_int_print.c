//#include "../inc/pathfinder.h"
#include "pathfinder.h"

static void print_int(int n);

void mx_int_print(int n) {
    if (n == -2147483648)
        write(1, "-2147483648", 11);
    else {
        print_int(n);
    }
}

static void print_int(int n) {
    if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    if (n <= 9) {
        mx_printchar(n + 48);
    }
    if (n > 9) {
        print_int(n / 10);
        print_int(n % 10);
    }
}

