#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i, x;
  char buf[MAX_BUF];

  do{
    fgets(buf, MAX_BUF, stdin);
    len = strlen(buf);
    for (i = 0; i <= len; i++){
      if(buf[i] >= 'a' && buf[i] <= 'z'){
        x = buf[i] - 'a';
        letter_frequency[x]++;
      }
      if(buf[i] >= 'A' && buf[i] <= 'Z'){
        x = buf[i] - 'A';
        letter_frequency[x]++;
      }
      if(buf[i] != '\0'){
        buf[i] = '\0';
      }
    }
  }while(fgets(buf, MAX_BUF, stdin) != NULL);

  // fgets(buf, MAX_BUF, stdin);
  // len = strlen(buf);

  // while(buf[len] != NULL && buf[len-1] != NULL){
  //   fgets(buf, MAX_BUF, stdin);
  //   len = strlen(buf);
  // }

  // while(fgets(buf, MAX_BUF, stdin) != NULL){
  //   len += strlen(buf);
  // }

  // while(fgets(buf, MAX_BUF, stdin) != NULL){
  //   len += strlen(buf) - 1;
  //   char a = buf[len];
  //   char b = buf[len-1];
  //   if(a == NULL && b == NULL){
  //     buf[len] == fgets(buf, MAX_BUF, stdin);
  //   }
  // }

  // for (i = 0; i < len; i++){
  //   if(buf[i] >= 'a' && buf[i] <= 'z'){
  //     x = buf[i] - 'a';
  //     letter_frequency[x]++;
  //   }
  //   if(buf[i] >= 'A' && buf[i] <= 'Z'){
  //     x = buf[i] - 'A';
  //     letter_frequency[x]++;
  //   }
  // }

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}