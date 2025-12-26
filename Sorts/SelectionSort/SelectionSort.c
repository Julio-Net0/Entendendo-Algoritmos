#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.c"

#define LEN 100000

void selectionSort(int list[], int len);

int main()
{
  int *list = malloc(LEN * sizeof(int));
  generateWorstCase(list, LEN);

  clock_t start = clock();

  selectionSort(list, LEN);
    
  clock_t end = clock();

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f seconds\n", cpu_time_used);

  validateSort(list, LEN);

  free(list);
  return EXIT_SUCCESS;
}

int findIndexSmallest(const int list[], int start, int len) {
  int smallestIndex = start;

  for(int i = start + 1; i < len; i++) {
    if(list[i] < list[smallestIndex]) {
      smallestIndex = i;
    }
  }
  return smallestIndex;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int list[], int len) {
  for (int i = 0; i < len - 1; i++) {
    
    int smallestIndex = findIndexSmallest(list, i, len);

    if(smallestIndex != i) {
        swap(&list[i], &list[smallestIndex]);
    }
  }
}
