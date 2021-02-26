#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
  //TODO: your implementation
  int i, j, d, count = 0;;
  char *bin, *b;

  bin = (char*)malloc(sizeof(char)* 32);
  b = (char*)malloc(sizeof(char)* 42);
  b[0] = '0', b[1] = 'b';
  
  for(i = 31; i >= 0; i--){
    d = dec >> i;
    *(bin+count) = (d & 1) ? '1':'0';
    count++;
  }

  int n = 2;

  for(j = 0; j < 32; j++){
    if(n%5 == 1){
      b[n] = ' ';
      n++;
      b[n] = bin[j];
    }
    else{
      b[n] = bin[j];
    }
    n++;
  }
  b[41] = ' ';
  free(bin);

  return b;

}

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s\n", n, bin);
	//TODO: do we need to release the memory of bin?
  free(bin);
}
