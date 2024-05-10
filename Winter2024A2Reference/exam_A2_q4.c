#include <stdio.h>
#include <stdlib.h>

#define NO_FITTING_IDX -1

int exam_A2_q4(int arr[], int n, int d, int target);
int sum_of_digits_by_base(int num, int base);

int main(void) {
    int n, d, target;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int *arr = (int *)malloc(sizeof(int) * n);
    if (!arr) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return 1;
        }
    }

    if (scanf("%d%d", &d, &target) != 2) {
        free(arr);
        return 1;
    }

    printf("%d", exam_A2_q4(arr, n, d, target));
    free(arr);
    return 0;
}

/* Your code here */

int exam_A2_q4(int arr[], int n, int d, int target) {
    // Arr is empty, thus no idx fitting the requirement
    if (n == 0) {
        return NO_FITTING_IDX;
    }
    // Check sum of digs by base d of curr idx
    int sum_of_digs = sum_of_digits_by_base(arr[0], d);
    // If fits target, then return 0 (this idx)
    if (sum_of_digs == target) {
        return 0;
    }
    // Try checking recursively for fitting idx
    int fittingIndex = exam_A2_q4(arr + 1, n - 1, d, target);
    // If not found, pass that info on
    if (fittingIndex == NO_FITTING_IDX) {
        return NO_FITTING_IDX;
    }
    // If found an idx, then returned val is the idx relative to the "child"
    // in the stack
    // Thus, add 1 to make the idx relative to yourself
    return fittingIndex + 1;
}

int sum_of_digits_by_base(int num, int base) {
    if (num == 0) {
        return 0;
    }
    return (num % base) + sum_of_digits_by_base(num / base, base);
}
