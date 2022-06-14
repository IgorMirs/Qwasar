char* my_strstr(char* param_1, char* param_2) {
    if (*param_2 == 0) {
        return param_1;
    }
    for(int i = 0; param_1[i] != 0; i++) {
        if (param_1[i] == param_2[0]) {
            int j = 1, k = i + 1;
            while (param_2[j] != 0) {
                if (param_2[j] != param_1[k++]) {
                    break;
                }
                j++;
            }
            if (param_2[j] == 0) {
                return (param_1 + i);
            }
        }
    }
    return 0;
}