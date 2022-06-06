function my_average_mark(param_1) {
    var sum = 0;
    for (var i = 0; i < param_1.length; i++) {
        sum += (Object.values(param_1[i])[1]);
    }
    return (sum/param_1.length).toFixed(1);
}
