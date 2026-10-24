#include <string.h>
#include <stdlib.h>

// Helper to expand around center and return the length of the palindrome
static int expandAroundCenter(const char *s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length is (right - 1) - (left + 1) + 1 = right - left - 1
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (!s) return NULL;
    
    int n = strlen(s);
    if (n < 2) return s;

    int start = 0;
    int max_len = 1;

    for (int i = 0; i < n; i++) {
        // Odd length palindromes (single character center: e.g., "aba")
        int len1 = expandAroundCenter(s, i, i, n);
        
        // Even length palindromes (two character center: e.g., "abba")
        int len2 = expandAroundCenter(s, i, i + 1, n);

        int len = len1 > len2 ? len1 : len2;

        if (len > max_len) {
            max_len = len;
            // Calculate the starting index of the palindrome
            start = i - (len - 1) / 2;
        }
    }

    // Allocate memory for the result string (+1 for null-terminator)
    char *result = (char *)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
}