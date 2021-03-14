/******************************************************
* File: vector.h
*
* This is the header file vector.c
*
******************************************************/
//This is the header guide.
// #ifndef VECTOR_H_232
// #define VECTOR_H_232
#include "frame.h"

typedef struct vector {
   int size;
   frame_t ** data;
} vector_t;

typedef struct vector vector_t;
vector_t * vector_new();
void vector_delete(vector_t *);
void vector_set(vector_t*,  int loc,  struct frame_t* val);
char* vector_get_frame_content(vector_t *, int loc);
int vector_get_frame_rep_counter(vector_t * v, int i);