char* reverse_string(char* param_1) {
    int start = 0, end = 0;
    //find the end
    while (param_1[end] != 0) {
        end++;
    }
    end--;
    //exchange characters
    while (start < end) {
        char temp = param_1[start];
        param_1[start++] = param_1[end];
        param_1[end--] = temp;
    }
    return param_1;
}