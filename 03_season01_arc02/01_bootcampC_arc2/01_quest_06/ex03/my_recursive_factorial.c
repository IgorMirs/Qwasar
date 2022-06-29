int my_recursive_factorial(int num) {
    if (num < 0) {
        return 0;
    }
    else if (num == 0) {
        return 1;
    }
    else {
        return num * my_recursive_factorial(num - 1);
    }

}