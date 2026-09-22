int lengthOfLongestSubstring(char* s) {
    int last_index[256];
    for (int i = 0; i < 256; i++) {
        last_index[i] = -1;
    }

    int max_len = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = (unsigned char)s[right];

        if (last_index[c] >= left) {
            left = last_index[c] + 1;
        }

        last_index[c] = right;

        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    return max_len;
}
