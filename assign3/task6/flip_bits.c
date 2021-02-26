#include <stdio.h>
#include <stdlib.h>

// Note, the bits are counted from right to left. 
// Flip the bits of x within range [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
void flip_bits(unsigned * x,
              unsigned start,
              unsigned end) {
    // YOUR CODE HERE
    int s, e, i;
    unsigned int* bin = (unsigned int *)malloc(sizeof(unsigned int )* 32);
    s = 32 - start - 1;
    e = 32 - end - 1;

  
    for(i = 31; i >= 0; i--){
      bin[i] = *x&1;          //changes x to binary
      *x >>= 1;
    }

    for(i = s; i >= e; i--){
      bin[i] = (bin[i] ^ 1);  //flips the elements in range
    }

    unsigned int n = 0;

    for (i = 0; i < 32; ++i) {
      n*=2;
      n = n + bin[i];       //converts binary to decimal
    }
    *x = n;
    free(bin);
}