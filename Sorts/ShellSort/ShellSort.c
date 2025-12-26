#include <stdio.h>
#include <stdlib.h>

void shellSort(int list[], int len);

int main()
{
  int list[] = {5, 6, 10, 9, 2, 3, 4};
  int listLen = sizeof(list) / sizeof(list[0]);

  shellSort(list, listLen);

  for(int i = 0; i < listLen; i++) {
      printf("%d\n", list[i]);
  }

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
