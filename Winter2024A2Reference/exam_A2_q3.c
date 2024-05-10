#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 30
#define ABC 'z' - 'a' + 1

int exam_A2_q3(char *str1, char *str2);
bool is_almost_permutation(int str2_hist[], int str1_substr_hist[]);

int main(void) {
    char str1[MAX_LEN] = {0}, str2[MAX_LEN] = {0};
    if (scanf(" %s %s", str1, str2) != 2) {
        return 1;
    }
    printf("%d", exam_A2_q3(str1, str2));
    return 0;
}

/* Your code here */

int exam_A2_q3(char *str1, char *str2) {
    int str1_substr_hist[ABC] = {0};
    int str2_hist[ABC] = {0};
    int str2_len = 0;
    // Fill hist for str2 and str1 until reaching end of str2
    while (str2[str2_len]) {
        str2_hist[str2[str2_len] - 'a']++;
        str1_substr_hist[str1[str2_len] - 'a']++;
        str2_len++;
    }
    int total_almost_perms = 0;

    // Add next letter to str1 hist because we need to start checking from
    // substring of str1 starting at 0 ending at str2_len if almost permutation
    str1_substr_hist[str1[str2_len] - 'a']++;

    total_almost_perms += is_almost_permutation(str2_hist, str1_substr_hist);
    // To check for almost permutations, we need substrings of str1
    // that have a length of str2_len + 1, thus this is the window's size
    int window_size = str2_len + 1;
    // We already checked first possible permutation of window, thus start here
    for (int index = window_size; str1[index]; index++) {
        str1_substr_hist[str1[index - window_size] - 'a']--;
        str1_substr_hist[str1[index] - 'a']++;
        total_almost_perms += is_almost_permutation(str2_hist,
                                                    str1_substr_hist);
    }
    return total_almost_perms;
}

bool is_almost_permutation(int str2_hist[], int str1_substr_hist[]) {
    int total_letters_diff = 0;
    for (int i = 0; i < ABC; i++) {
        // str2 can't be almost permutation of substr1 if it has more
        // occurrences of a letter
        if (str1_substr_hist[i] < str2_hist[i]) {
            return false;
        }
        // Add the diff in letter appearance between substr1 and str2 (non neg)
        total_letters_diff += str1_substr_hist[i] - str2_hist[i];
    }
    // We expect a total diff of exactly one in order to have it be an
    // "almost permutation"
    return total_letters_diff == 1;
}
