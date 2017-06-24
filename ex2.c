// Write a program in C to read n number of values in an array and display it in reverse order

#include <stdio.h>

void main(){

  int length;
  int i;

  printf("Input the number of elements to store in the array: ");
  scanf("%d", &length);
  printf("Input %d number of elements in the array\n", length);

  int array[length];

  for(i = 0; i < length; i++){
    printf("Element %d: ", i);
    int arrayIndex = length - 1 - i;
    scanf("%d", &array[arrayIndex]);
  }

  for(i = 0; i < length; i++){
    printf("%d", array[i]);
  }
}