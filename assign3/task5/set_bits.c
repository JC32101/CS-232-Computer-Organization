#include <stdio.h>
#include <stdlib.h>

// Set the bits of x within range of [start, end], in which both are inclusive
// Assume 0 <= start & end <= 31
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v) {
    // YOUR CODE HERE
    // No return value
    // v points to an array of at least (end-start+1) unsigned integers.
    // if v[i] == 0, then set (i+start)-th bit of x zero, otherwise, set (i+start)-th bit of x one.
    int s, e, i, j;
    unsigned int* bin = (unsigned int *)malloc(sizeof(unsigned int )* 32);
    s = 32 - start - 1;
    e = 32 - end - 1;

  
    for(i = 31; i >= 0; i--){
      bin[i] = *x&1;                //changes x to binary
      *x >>= 1;
    }

    j = 0;
    for(i = s; i >= e; i--){
      if(bin[i] != v[j]){
        bin[i] = (bin[i] & 1) ^ 1;  //set the elements in range = to v
      }
      j++;
    }

    unsigned int n = 0;

    for (i = 0; i < 32; ++i) {
      n*=2;
      n = n + bin[i];             //converts binary to decimal
    }
    *x = n;
    free(bin);
}