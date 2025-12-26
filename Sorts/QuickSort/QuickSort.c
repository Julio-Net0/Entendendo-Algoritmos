#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils.c"

#define LEN 100000

void quickSort(int list[], int len);

int main() {
    int *list = malloc(LEN * sizeof(int));
    if (list == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    generateRandomCase(list, LEN);

    clock_t start = clock();
    quickSort(list, LEN);
    clock_t end = clock();

    double time_random = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Random: %f seconds\n\n", time_random);

    generateWorstCase(list, LEN);
    start = clock();
    quickSort(list, LEN);
    end = clock();

    double time_worst = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Worst: %f seconds\n", time_worst);

    free(list);
    return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int list[], int low, int high) {
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (list[j] < pivot) {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    
    swap(&list[i + 1], &list[high]);
    
    return i + 1;
}

void quickSortRecursion(int list[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(list, low, high);

        quickSortRecursion(list, low, pivotIndex - 1);

        quickSortRecursion(list, pivotIndex + 1, high);
    }
}

void quickSort(int list[], int len) {
    quickSortRecursion(list, 0, len - 1);
}
