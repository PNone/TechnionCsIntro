#include <stdio.h>

int main(void) {
    int question;
    char complexity;
    scanf("%d", &question);
    scanf("%c", &complexity);

    if (complexity == 't') {
        switch (question) {
            case 1:
                printf("The time complexity of f1 is: %s\n", "c");
                break;
            case 2:
                printf("The time complexity of f2 is: %s\n", "e");
                break;
            case 3:
                printf("The time complexity of f3 is: %s\n", "g");
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
    if (complexity == 's') {
        switch (question) {
            case 1:
                printf("The space complexity of f1 is: %s\n", "a");
                break;
            case 2:
                printf("The space complexity of f2 is: %s\n", "a");
                break;
            case 3:
                printf("The space complexity of f3 is: %s\n", "k");
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
    return 0;

}
