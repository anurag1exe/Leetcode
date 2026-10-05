#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    if (s == NULL) return true;

    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }
    char* stack = (char*)malloc(len * sizeof(char));
    if (stack == NULL) {
        return false;
    }

    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }

            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}