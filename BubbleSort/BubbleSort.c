#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *bubbleSort(const int list[], int len);

int main()
{
  int list[] = {5, 6, 10, 9, 2, 3, 4};
  int listLen = sizeof(list) / sizeof(list[0]);

  int *sortedList = bubbleSort(list, listLen);

  if (sortedList != NULL) {
    for(int i = 0; i < listLen; i++) {
        printf("%d\n", sortedList[i]);
    }
    free(sortedList);
  }

  return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *bubbleSort(const int list[], int len) {

  int *newList = malloc(len * sizeof(int));
  
  if (newList == NULL) return NULL;

  memcpy(newList, list, len * sizeof(int));

  bool swaped = false;

  for(int i = 0; i < len; i++){
    for(int y = 0; y < len - i - 1; y++){
      if(newList[y] > newList[y+1]){
        swap(&newList[y], &newList[y+1]); 
        swaped = true;
      }
    }
    if(!swaped){
      break;
    }
  }

  return newList;
}
