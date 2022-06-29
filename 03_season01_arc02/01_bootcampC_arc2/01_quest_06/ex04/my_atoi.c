int my_atoi(char* str) {
    //remove leading spaces
    while (*str == '\t' || *str == ' ') {
        str++;
    }
    int res = 0;
    int sign = 0;
    if (*str == '-') {
        sign = 1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        res *= 10;
        res += (*str) - '0';
        str++;
    }

    return (sign) ? (res * -1) : res;
}
