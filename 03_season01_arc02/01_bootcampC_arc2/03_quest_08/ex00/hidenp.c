int hidenp(char* s1, char* s2) {
    if (*s1 == 0) {
        return 1;
    }
    for(int i = 0, j = 0; s1[i] != 0; ) {
        while(s2[j] != s1[i] && s2[j] != 0) {
            j++;
        }
        i++;
        if (s1[i] == 0) {
            return 1;
        }
        else if (s2[j] == 0) {
            return 0;
        }
    }
    return -1;
}