#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.c"

#define LEN 100000

void shellSort(int list[], int len);

int main() {
    int *list = malloc(LEN * sizeof(int));
    if (list == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    generateRandomCase(list, LEN);

    clock_t start = clock();
    shellSort(list, LEN);
    clock_t end = clock();

    double time_random = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Random: %f seconds\n\n", time_random);

    generateWorstCase(list, LEN);
    start = clock();
    shellSort(list, LEN);
    end = clock();

    double time_worst = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Worst: %f seconds\n", time_worst);

    free(list);
    return EXIT_SUCCESS;
}

void shellSort(int list[], int len) {
  for(int gap = len/2; gap > 0; gap /=2){
    for(int i = gap; i < len; i++){
      int temp = list[i];
      int ind = i;

      while(ind >= gap && list[ind-gap] > temp){
        list[ind] = list[ind-gap];
        ind -= gap;
      }
      list[ind] = temp;
    }
  }
}
