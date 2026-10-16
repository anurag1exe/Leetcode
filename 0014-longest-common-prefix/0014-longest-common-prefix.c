#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    // Handle invalid inputs or empty arrays to prevent segmentation faults
    if (strs == NULL || strsSize <= 0) {
        char* empty_str = (char*)malloc(1 * sizeof(char));
        if (empty_str != NULL) {
            empty_str[0] = '\0';
        }
        return empty_str;
    }

    // The maximum possible length of the prefix is the length of the first string
    int max_possible_len = strlen(strs[0]);
    char* prefix = (char*)malloc((max_possible_len + 1) * sizeof(char));
    
    // Handle extreme out-of-memory errors gracefully
    if (prefix == NULL) {
        return NULL; 
    }

    // Iterate column by column (character index)
    for (int i = 0; i < max_possible_len; i++) {
        char current_char = strs[0][i];
        
        // Compare the current character across all other strings
        for (int j = 1; j < strsSize; j++) {
            // Stop if we hit a mismatch or reach the end of any string prematurely
            if (strs[j][i] == '\0' || strs[j][i] != current_char) {
                prefix[i] = '\0'; // Null-terminate at the mismatch
                return prefix;
            }
        }
        // If all strings match at this index, append to our prefix
        prefix[i] = current_char;
    }

    // If the loop completes, the entire first string is the common prefix
    prefix[max_possible_len] = '\0';
    return prefix;
}