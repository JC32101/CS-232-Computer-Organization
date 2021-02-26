#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, the bits are counted from right to left. 
// Return the bit states of x within range of [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
unsigned * get_bits(unsigned x,
                 unsigned start,
                 unsigned end) {
    
   //return NULL;
    // YOUR CODE HERE
    // Returning NULL is a placeholder
    // get_bits dynamically allocates an array a and set a[i] = 1 when (i+start)-th bit
    // of x is 1, otherwise set a[i] = 0;
    // At last, get_bits returns the address of the array.

    int i, range, j, s, e;
    range = end - start + 1;
    unsigned *p_a = (unsigned *)malloc(sizeof(unsigned)* range);
    unsigned *bin = (unsigned *)malloc(sizeof(unsigned)* 32);

    s = 32-start-1;
    e = 32-end-1;

    for(i = 31; i >= 0; i--){
      bin[i] = x&1;             //changes x to binary
      x >>= 1;
    }

    j = 0;
    for(i = s; i >= e; i--){
      p_a[j] = bin[i];          //stores the range elements into p_a
      j++;
    }

    free(bin);

    return p_a;
}