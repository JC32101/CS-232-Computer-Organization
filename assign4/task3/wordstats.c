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
  // do{
  //   fgets(buf, MAX_BUF, stdin);
  //   len += strlen(buf) - 1;
  //   if(buf[len] == '\n'){
  //     break;
  //   }
  // }while(len > 1);

  // for(i = 0; i < MAX_BUF; i++){
  //     fgets(buf[i], MAX_BUF, stdin);
  // }


  // while(fgets(buf, MAX_BUF, stdin) != NULL){
  //   len += strlen(buf) - 1;
  //   // if(buf[len] == NULL){
  //   //   buf[len] == fgets(buf, MAX_BUF, stdin);
  //   // }
  // }

  while((x=getchar()) != EOF){
    buf[len] = x;
    len++;
  }

  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/

  // printf("length of buf: %i\n", len);

  // printf("Buf Array: \n");
  // for(i = 0; i < len; i++){
  //   printf("%c", buf[i]);
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

  // for(i = 0; i < 26; i++){
  //   printf("%i: %i", i, letter_frequency[i]);
  // }
  // printf("\n");

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}