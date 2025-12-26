#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateWorstCase(int *list, int len) {
    for (int i = 0; i < len; i++) {
        list[i] = len - i;
    }
}

void generateRandomCase(int *list, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        list[i] = rand() % len;
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
