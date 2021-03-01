/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>

#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

<<<<<<< HEAD
int main()
{
  char * Strings[NUM];
  int i, m;
  
  char t [LEN-2];

  for(i = 0; i < NUM; i++){
      fgets(t, LEN-2, stdin);
      char *s = (char*)malloc(sizeof(strlen(t)+2));
      for(m = 0; m < strlen(t); m++){
        *(s+m) = *(t+m);
=======
int mystrcmp(char * a, char * b){
  while(*a != '\0' && *b != '\0'){
    if(a == b){
      a++, b++;
    }
    else if ((*a == '\0' && *b != '\0') || (*a != '\0' && *b == '\0') || *a != *b){
      return 1;
      break;
    }
  }
  return 0;
}

void swap(char *c, char *d){
  char *temp = *c;
  *c = *d;
  *d = temp;
}

int main()
{
  char * Strings[NUM];

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings.

  Use fgets(), with LEN as an argument to ensure that an input line that is too
  long does not exceed the bounds imposed by the string's length. However, each 
	string stored in array Strings must not waste space. That is, only the buffer
	used by fgets() to temporary store the string read from input stream needs to 
	be LEN bytes long.  
	Note that the newline and NULL characters will be included in LEN.
  */
  int i, m;

  
  char temp [LEN-2];

  for(i = 0; i < NUM; i++){
      fgets(temp, LEN-2, stdin);
      char *s = (char*)malloc(sizeof(strlen(temp)+1));
      for(m = 0; m < strlen(temp); m++){
        *(s+m) = *(temp+m);
>>>>>>> 861892eccc25f8bda3ef780b01ac6cc42a3bf3a1
      }
      *(s+m-1) = '\0';
      Strings[i] = s;
<<<<<<< HEAD
  }
=======
  }

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */

  for(i = 0; i < NUM; i++){
    printf("%s\n", *(Strings+i));
  }
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
      (i) The comparison of two strings must be done by checking them one
          character at a time, without using any C string library functions.
          That is, write your own while/for loop to do this.
      (ii)  Implement a swap function to swap two strings by swapping pointers without copying any chars. You are not allowed to use any C library functions in swap.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
>>>>>>> 861892eccc25f8bda3ef780b01ac6cc42a3bf3a1
  
  int j;
  int k;

<<<<<<< HEAD
  for(k = 0; k < NUM; k++){
    for(i = 0; i < NUM-1; i++){
      for(j = 0; (*(*(Strings + i) +j) != '\0') && (*(*(Strings + i + 1) +j) != '\0'); j++){
        if(*(*(Strings+i)+j) > *(*(Strings+i+1)+j)){
          char *temp = Strings[i];
          Strings[i] = Strings[i+1];
          Strings[i+1] = temp;
          break;
        }
        else if (*(*(Strings+i)+j) < *(*(Strings+i+1)+j)) {
          break;
        }
=======
  for(j = 1; j <= NUM; j++){
    for(k = 0; k <= NUM - j; k++){
      // int l = k +1;
      // if(mystrcmp(*(Strings+k),*(Strings+l))>0){
      //   //swap(&Strings[k], &Strings[k+1]);
      //   char *temp = *(Strings+k);
      //   *(Strings+k) = *(Strings+l);
      //   *(Strings+l) = temp;
      // }
      if(mystrcmp(Strings[j], Strings[j+1]) > 0){
        temp(Strings[j], Strings[j+1]);
>>>>>>> 861892eccc25f8bda3ef780b01ac6cc42a3bf3a1
      }
    }
  }
  
  int l;
  for(l = 0; l < NUM; l++){
    printf("%s\n", Strings[l]);
  }
  for(l = 0; l < NUM; l++){
    free(*(Strings+l));
  }
}