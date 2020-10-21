#include "libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int a = 1;  

    if(*str == '-'){
        a = -1;
        str ++;
    }
    while(*str !='\0') {
        if (mx_isspace(*str))
            str++;
        if (mx_isdigit(*str)) {
            i *= 10;
            i += *str;
            str++;
            i -= '0';
        }
    }
    return i * a;
}
