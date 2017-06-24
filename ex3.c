// Write a program in C to count a total number of duplicate elements in an array

#include <stdio.h>
#include <stdlib.h>

int * getArray(int size){

  int *array = malloc(size);
  int i;

  for(i = 0; i < size; i++){
    printf("Set index %d: ", i);
    scanf("%d", &array[i]);
  }

  return array;
}

void displayArray(int array[], int size){
  int i;

  for(i = 0; i < size; i++){
    printf("%d\n", array[i]);
  }
}

void main(){

  int size;

  printf("Size of array: ");
  scanf("%d", &size);

  int *myArray =  getArray(size);
  displayArray(myArray, size);
}