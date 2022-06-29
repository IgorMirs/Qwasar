int my_iterative_factorial(int num) {
    if (num < 0) {
        return 0;
    }
    int res = 1;
    while (num > 0) {
        res *= num--;
    }

    return res;
}
