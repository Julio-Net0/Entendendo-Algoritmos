#include <stdio.h>
#include <stdlib.h>

void insertionSort(int list[], int len);

int main()
{
  int list[] = {5, 6, 10, 9, 2, 3, 4};
  int listLen = sizeof(list) / sizeof(list[0]);

  insertionSort(list, listLen);

  for(int i = 0; i < listLen; i++) {
      printf("%d\n", list[i]);
  }

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
