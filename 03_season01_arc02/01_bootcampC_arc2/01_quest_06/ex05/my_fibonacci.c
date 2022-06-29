int my_fibonacci(int num) {
    if (num < 0) {
        return -1;
    }
    else if(num == 0 || num == 1) {
        return num;
    }
    int first = 0, second = 1, fibonacciNum = 0;

    for(int i = 2; i <= num; i++) {
        fibonacciNum = first + second;
        first = second;
        second = fibonacciNum;
    }

    return fibonacciNum;
    
}