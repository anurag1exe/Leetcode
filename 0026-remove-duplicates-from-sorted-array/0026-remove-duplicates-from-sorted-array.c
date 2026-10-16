#include <stdio.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize) {
    // A length of 0 means 0 unique elements.
    // Failing to check this before accessing nums[0] will cause a segmentation fault.
    if (numsSize == 0) {
        return 0;
    }

    // k tracks the index where the next unique element should be placed.
    // Since nums[0] is inherently unique to itself, we start k at 1.
    int k = 1;

    for (int i = 1; i < numsSize; i++) {
        // Since the array is sorted, duplicates are adjacent.
        // We only take action when the current element differs from the previous one.
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}