#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int list[], int len);


int main()
{
  int list[] = {5, 6, 10, 9, 2, 3, 4};
  int listLen = sizeof(list) / sizeof(list[0]);

  bubbleSort(list, listLen);

  for(int i = 0; i < listLen; i++) {
      printf("%d\n", list[i]);
  }

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
