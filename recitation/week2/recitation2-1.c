#include <stdio.h>

void printArray(int a[], int size);
int minimum(int a[], int size);

int main(){
  int data[10] = {5, 8, 9, 1, 10, 12, 4, 3, 7, 13}; //all have to be the same type
  int opposite[10]; //need to specify the type
  int min, i;

  for(i = 0; i < 10; i++){
    opposite[i] = -(data[i]);
  }

  printArray(data, 10);
  min = minimum(data, 10);
  printf("Smallest value in data is: %d\n", min);

  printArray(opposite, 10);
  min = minimum(opposite, 10);
  printf("Smallest value in opposite is: %d\n", min);

  return 0;

}

//prints out the content of the array
void printArray(int a[], int size){
  int i;
  printf("Array Contents:\n");
  for(i = 0; i < size; i++){
    printf("%d", a[i]);
  }

  printf("\n");

}

int minimum(int a[], int size){
  int low, i;
  low = a[0];

  for(i = 1; i < size; i++){
    if(a[i] < low){
      low = a[i];
    }
  }
  return low;
}