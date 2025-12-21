#include <stdio.h>
#include <stdlib.h>

//For a list with n values, the binary search will be able to find the value in log2(n) iterations max.

int binarySearch(const int list[], int len, int search);

int main()
{
  int myList[] = {1,2,3,4,5,6,7,8,9,10};
  int len_myList = sizeof(myList) / sizeof(myList[0]);

  printf("%d\n", binarySearch(myList, len_myList, 10));

  return EXIT_SUCCESS;
}

int binarySearch(const int list[], int len, int search){

  int low = 0, high = len - 1, mid, guess;

  while(low <= high){
    mid = low + (high - low) / 2; //same as '(low + high) / 2', changed to subtraction to avoid 'Integer Overflow'
    guess = list[mid];

    if(guess == search)
      return mid;
    if(guess > search)
      high = mid - 1;
    else 
      low = mid + 1;
  }

  return -1; //Numer not found on the list
}
