#include <string.h>

int strStr(char * haystack, char * needle) {
    // Handle edge cases for null pointers
    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    
    int h_len = strlen(haystack);
    int n_len = strlen(needle);
    
    // An empty needle is conventionally found at index 0
    if (n_len == 0) {
        return 0;
    }
    
    // If needle is longer than haystack, it cannot be found
    if (n_len > h_len) {
        return -1;
    }
    
    // Iterate through haystack up to the last possible fitting index
    for (int i = 0; i <= h_len - n_len; i++) {
        int j = 0;
        
        // Check if the substring matches the needle
        while (j < n_len && haystack[i + j] == needle[j]) {
            j++;
        }
        
        // If we matched all characters in the needle, return the starting index
        if (j == n_len) {
            return i;
        }
    }
    
    return -1;
}