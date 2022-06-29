int my_recursive_pow(int base, int pow) {
    if (pow < 0) {
        return 0;
    }
    //base case 
    if (pow == 0) {
        return 1;
    }
    //recursive case
    else {
        return base * my_recursive_pow(base, pow - 1);
    }
}
