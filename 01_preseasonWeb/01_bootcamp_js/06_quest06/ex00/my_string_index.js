function my_string_index(haystack, needle) {
    i = 0, length = haystack.length;
    while (i < length) {
        if (haystack[i++] == needle) {
            return i - 1;
        }
    }
    return -1;
}