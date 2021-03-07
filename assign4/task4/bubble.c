/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>

#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

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
      }
      *(s+m-1) = '\0';
      Strings[i] = s;
  }

  int j;
  int k;

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