#include "libmx.h"

static char *plus(int num, char *str) {
    str[0] = num + '0';
    str[1] = '\0';
    return str;
}

static char *min(int num, char *str) {
    int m =1;
    int i = 1;
    int k = num;

    while (k) {
        k = k / 10;
        m++;
    }
    str[0] = '-';
    num *= -1;
    for (; m > i; m--) {
        str[m - 1] = num % 10 + 48;
        num /= 10;
    }
    return str;
}

static char *max_plus(int num, char *str) {
    int k = num;
    int m = 0;
    int i = 0;

    while (k) {
        k = k / 10;
        m++;
    }
    for (; m > i; m--) {
        str[m - 1] = num % 10 + 48;
        num /= 10;
    } 
    return str;
}

char *mx_itoa(int number) {
    char *str = (char*) malloc (sizeof(char) * 12);

    if(number >= 0 && number <= 9)
        plus(number, str);
    if(number >= 9)
        max_plus(number, str);
    if (number == -2147483648)
        return "-2147483648";
    if (number < 0)
        min(number, str);
    return str; 
}

