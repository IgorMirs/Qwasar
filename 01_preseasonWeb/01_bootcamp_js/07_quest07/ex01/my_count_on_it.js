function my_count_on_it(param_1) {
    length = param_1.length;
    res = new Array(length).fill(0);
    for (i = 0; i < length; i++) {
        res[i] = param_1[i].length;
    }
    return res;
}