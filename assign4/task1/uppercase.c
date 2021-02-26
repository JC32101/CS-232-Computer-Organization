#include <stdio.h>

int main(int argc, char *argv[]) {
/* example:
 *  char str[10090];
  int ch, n = 0;

  //EOF = end-of-file
  while ((ch = getchar()) != EOF && n < 1000) {
    str[n] = ch;
    ++n;
  }

  for (int i = 0; i < n; ++i)
    putchar(str[i]);

  return 0;

  */
  char arr[1000];
  int i, c, count;
  count = 0;

  while ((c = getchar()) != EOF){
    arr[count] = c;
    count++;
  }

  for (i = 0; i < count; i++){
    if(arr[i] < 97){
      putchar(arr[i]);
    }
    else{
      arr[i]-=32;
      putchar(arr[i]);
    }
  }
  

  return 0;
}

