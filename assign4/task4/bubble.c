/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int mystrcmp(char * a, char * b){
  while(*a != '\0' && *b != '\0'){
    if(*a == *b){
      a++, b++;
    }
    else{
      return 1;
    }
  }
  return 0;
}

void swap(char **c, char **d){
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
  int i;

  char temp [LEN-2];

  for(i = 0; i < NUM; i++){
<<<<<<< HEAD
      fgets(temp, LEN-2, stdin);
      char *s = (char*)malloc(sizeof(strlen(temp)+1));
      for(m = 0; m < strlen(temp); m++){
        *(s+m) = *(temp+m);
      }
      *(s+(strlen(s)-1)) = '\0';
      Strings[i] = s;
=======
      fgets(s, LEN-2, stdin);
      Strings[i] = &s[i];
>>>>>>> 38df14360c33992a8cbdaeef3a099e850840a9d8
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

  int j;
  int k;

  for(j = 1; j < NUM; j++){
    for(k = 0; k < NUM - j - 1; k++){
      if(mystrcmp(Strings[k], Strings[k+1])>0){
        swap(&Strings[k], &Strings[k+1]);
      }
    }
  }

  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  int l;
  for(l = 0; l < NUM; l++){
    printf("%s\n", Strings[l]);
    free(*(Strings+i));
  }
}
