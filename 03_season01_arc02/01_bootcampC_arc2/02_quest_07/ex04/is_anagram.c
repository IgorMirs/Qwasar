int my_strlen(char* s) {
    int res = 0;
    while (*s != 0) {
        res++;
        s++;
    }

    return res;
}

int is_anagram(char* s1, char* s2) {
    if (my_strlen(s1) != my_strlen(s2)) {
        return 0;
    }
    
    int alph[128] = {0};
    for(int i = 0; s1[i] != 0; i++) {
        alph[(int)s1[i]]++;
    } 
    for(int i = 0; s2[i] != 0; i++) {
        alph[(int)s2[i]]--;
        if (alph[(int)s2[i]] < 0) {
            return 0;
        }
    }

    return 1;   
}
