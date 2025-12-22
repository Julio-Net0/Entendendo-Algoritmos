#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b);
int findIndexSmallest(const int list[], int start, int len);
int *selectionSort(const int list[], int len);

int main()
{
  int list[] = {5, 6, 10, 9, 2, 3, 4};
  int listLen = (int)(sizeof(list) / sizeof(list[0])); 

  int *sortedList = selectionSort(list, listLen);

  if (sortedList != NULL) {
    for(int i = 0; i < listLen; i++) {
        printf("%d\n", sortedList[i]);
    }
    free(sortedList);
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

int *selectionSort(const int list[], int len) {

  int *newList = malloc(len * sizeof(int));
  
  if (newList == NULL) return NULL;

  memcpy(newList, list, len * sizeof(int));

  for (int i = 0; i < len - 1; i++) {
    
    int smallestIndex = findIndexSmallest(newList, i, len);

    if(smallestIndex != i) {
        swap(&newList[i], &newList[smallestIndex]);
    }
  }
  return newList;
}
