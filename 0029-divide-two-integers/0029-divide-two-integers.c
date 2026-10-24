#include <limits.h>

int divide(int dividend, int divisor) {
    // 1. Edge case: 32-bit integer overflow
    // INT_MIN / -1 = 2147483648, which exceeds INT_MAX
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }

    // 2. Determine sign (1 if negative, 0 if positive)
    int negative = (dividend < 0) ^ (divisor < 0);

    // 3. Convert both to negative to avoid INT_MIN overflow
    int a = dividend < 0 ? dividend : -dividend;
    int b = divisor < 0 ? divisor : -divisor;

    int quotient = 0;

    // Both a and b are <= 0, so a <= b means |a| >= |b|
    while (a <= b) {
        int temp_b = b;
        int count = 1;

        // Use addition (temp_b + temp_b) instead of bit-shift (temp_b << 1)
        // to avoid undefined behavior on negative integers
        while (temp_b >= (INT_MIN - temp_b) && a <= (temp_b + temp_b)) {
            temp_b += temp_b;
            count += count;
        }

        a -= temp_b;
        quotient += count;
    }

    return negative ? -quotient : quotient;
}