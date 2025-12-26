#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.c"

#define LEN 100000

void insertionSort(int list[], int len);

int main()
{
  int *list = malloc(LEN * sizeof(int));
  generateWorstCase(list, LEN);

  clock_t start = clock();

  insertionSort(list, LEN);
    
  clock_t end = clock();

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f seconds\n", cpu_time_used);

  validateSort(list, LEN);

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
