#include <stdio.h>
#include <stdlib.h>

int exam_A2_q2(int arr[], int n, unsigned int target);
int find_max_k(int arr[], int n);
int array_k_sum(int arr[], int n, int k);

int main(void) {
    int n, target;
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
    if (scanf("%d", &target) != 1) {
        return 1;
    }

    printf("%d", exam_A2_q2(arr, n, target));
    free(arr);
    return 0;
}

/* Your code here */

int exam_A2_q2(int arr[], int n, unsigned int target) {
    int min_k = 0;
    int max_k = find_max_k(arr, n);
    // If biggest possible k's sum <= target, then it is closest by definition
    if (array_k_sum(arr, n, max_k) <= target) {
        return max_k;
    }

    // If we got here, k's value in the loop will never be max_k
    // Thus, k + 1 will be in valid range
    while (min_k < max_k) {
        int k = (min_k + max_k) / 2;
        int k_sum = array_k_sum(arr, n, k);
        if (target == k_sum) {
            return k;
            // k too big
        } else if (target < k_sum) {
            max_k = k - 1;
        } else {
            // (Next k is in valid range)
            // If it also has a sum <= target, then it is closer to it,
            // meaning min_k needs to be k + 1
            int next_k_sum = array_k_sum(arr, n, k + 1);
            if (next_k_sum <= target) {
                min_k = k + 1;
                // If sum of k+1 > target, then curr k is max possible valid k
            } else {
                max_k = k;
            }
        }
    }
    // This is the k with the sum closest but not bigger than target
    return min_k;
}

int find_max_k(int arr[], int n) {
    int max_k_value = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_k_value) {
            max_k_value = arr[i];
        }
    }
    return max_k_value;
}

int array_k_sum(int arr[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            sum += k;
        } else {
            sum += arr[i];
        }
    }
    return sum;
}
