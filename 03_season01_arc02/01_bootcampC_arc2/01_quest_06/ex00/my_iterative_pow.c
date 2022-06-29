int my_iterative_pow(int base, int pow) {
    if (pow < 0) {
        return 0;
    }
    int res = 1;
    for (int i = 0; i < pow; i++) {
        res *= base;
    }

    return res;
}
