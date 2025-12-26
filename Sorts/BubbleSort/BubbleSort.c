#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.c"

#define LEN 100000

void bubbleSort(int list[], int len);

int main()
{
  int *list = malloc(LEN * sizeof(int));
  generateWorstCase(list, LEN);

  clock_t start = clock();

  bubbleSort(list, LEN);
    
  clock_t end = clock();

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f seconds\n", cpu_time_used);

  validateSort(list, LEN);

  free(list);
  return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int list[], int len) {
  for(int i = 0; i < len; i++){
    bool swaped = false;
    for(int y = 0; y < len - i - 1; y++){
      if(list[y] > list[y+1]){
        swap(&list[y], &list[y+1]); 
        swaped = true;
      }
    }
    if(!swaped){
      break;
    }
  }
}
