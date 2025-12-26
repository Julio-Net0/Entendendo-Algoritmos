#include <stdio.h>

void generateWorstCase(int *list, int len) {
    for (int i = 0; i < len; i++) {
        list[i] = len - i;
    }
}
void validateSort(int *list, int len) {
    for (int i = 0; i < len - 1; i++) {
        if (list[i] > list[i+1]) {
            printf("Fail\n");
            return;
        }
    }
    printf("Success\n");
}
