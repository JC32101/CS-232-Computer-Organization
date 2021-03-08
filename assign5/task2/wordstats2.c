#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int len, i, character = 0, whitespace = 0, lowercase = 0, uppercase = 0, num = 0, line = 0, words = 0;
  char buf[MAX_BUF];


  while(fgets(buf, MAX_BUF, stdin) != NULL){

    len = strlen(buf);

    for (i = 0; i <= len; i++){
      character++;

      if(buf[i] == ' '){
        whitespace++;
      }
      if(buf[i] >= 'A' && buf[i] <= 'Z'){
        lowercase++;
      }
      if(buf[i] >= 'a' && buf[i] <= 'z'){
        uppercase++;
      }
      if(buf[i] >= '0' && buf[i] <= '9'){
        num++;
      }
    }
    line++;
  }

  character -= line;
  words = line + whitespace;

  printf("%i %i %i %i %i %i %i\n", character, words, line, whitespace, lowercase, uppercase, num);
}