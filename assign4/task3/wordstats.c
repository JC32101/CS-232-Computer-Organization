#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i, x;
  char buf[MAX_BUF];

  len = 0;

  //failed input 2 ---- only reads the first line ----- how can i read the second line?

  do{
    fgets(buf, MAX_BUF, stdin);
    len = strlen(buf) - 1;
  }while(len < 1);

  // while(fgets(buf, MAX_BUF, stdin) != NULL){
  //   len += strlen(buf) - 1;
  // }

  // while(fgets(buf, MAX_BUF, stdin) != NULL){
  //   len += strlen(buf) - 1;
  //   // if(buf[len] == NULL){
  //   //   buf[len] == fgets(buf, MAX_BUF, stdin);
  //   // }
  // }

  for (i = 0; i < len; i++){
    if(buf[i] >= 'a' && buf[i] <= 'z'){
      x = buf[i] - 'a';
      letter_frequency[x]++;
    }
    if(buf[i] >= 'A' && buf[i] <= 'Z'){
      x = buf[i] - 'A';
      letter_frequency[x]++;
    }
  }

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}