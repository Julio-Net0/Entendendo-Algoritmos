#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.c"

#define LEN 100000

void insertionSort(int list[], int len);

int main() {
    int *list = malloc(LEN * sizeof(int));
    if (list == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    generateRandomCase(list, LEN);

    clock_t start = clock();
    insertionSort(list, LEN);
    clock_t end = clock();

    double time_random = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Random: %f seconds\n\n", time_random);

    generateWorstCase(list, LEN);
    start = clock();
    insertionSort(list, LEN);
    end = clock();

    double time_worst = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Worst: %f seconds\n", time_worst);

    free(list);
    return EXIT_SUCCESS;
}

void insertionSort(int list[], int len) {
  for(int i = 1; i < len; i++){
    int temp = list[i];
    int ind = i;
    
    while(ind > 0 && list[ind - 1] > temp){
      list[ind] = list[ind - 1];
      ind--;
    }
    list[ind] = temp;
  }
}
