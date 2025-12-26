#include <stdio.h>
#include <stdlib.h>

void selectionSort(int list[], int len);

int main()
{
  int list[] = {5, 6, 10, 9, 2, 3, 4};
  int listLen = (int)(sizeof(list) / sizeof(list[0])); 

  selectionSort(list, listLen);

  for(int i = 0; i < listLen; i++) {
      printf("%d\n", list[i]);
  }

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
