function my_array_uniq(param_1) {
    dic = new Array(10).fill(0);
    for (i = 0; i < param_1.length; i++) {
        //found the duplicate
        if(dic[param_1[i]] == 1) {
            //delete the element from the array
            param_1.splice(i, 1);
            i--;
        }
        else {
            dic[param_1[i]] = 1;
        }
    }
    return param_1;
}