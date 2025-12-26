#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.c"

#define LEN 100000

void shellSort(int list[], int len);

int main()
{
  int *list = malloc(LEN * sizeof(int));
  generateWorstCase(list, LEN);

  clock_t start = clock();

  shellSort(list, LEN);
    
  clock_t end = clock();

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f seconds\n", cpu_time_used);

  validateSort(list, LEN);

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
