/******************************************************
* File: frame.c
*
* This is the frame struct implementation
*
******************************************************/
#include "frame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

static void load_frame(frame_t *f, char *path){
  char buf[MAX_BUF];
  FILE* fp;
  fp = fopen(path, "r");
  int m, i;
  i=0;
  // int index = 0;

  if (fp == NULL){
    exit(EXIT_FAILURE);
  }

  f->content = (char*)malloc(sizeof(char)*)
  while(fgets(buf, MAX_BUF, fp)){
    char *s = (char*)malloc(sizeof(strlen(buf)+2));
    for(m = 0; m < strlen(buf); m++){
      *(s+m) = *(buf+m);
    }
    *(s+m-1) = '\0';
    
    if(i == 0){
      f->rep_counter = s[0];
      i++;
    }

    frame_set(f, i, s);

    // f->content[index] = *s;
    // index++;

  }
  fclose(fp);
	return;
}

void frame_set(frame_t* f,  int loc, char* s){
	if((loc < strlen(f->content)) && (loc >= 0)) {
   	f->content[loc] = *s;
  } 
  else {
    f->content = (char*) realloc(f->content, sizeof(char)*(loc+1));

    for(int i = strlen(f->content); i < loc+1; i++)
		  f->content[i] = '\0';
    f->content[loc] = *s;
	}
}

// void frame_cat(frame_t *f, char *s2) {
// 	/* YOUR CODE HERE*/
//   size_t j;
  
//   for(j = 0; *(s2+j) != '\0'; j++) j++;
//   f->content = (char *)realloc(f->content, sizeof(char)*(sizeof(f->content) + j));
//   strcat(f->content, s2);
// }

frame_t * frame_new(char *pathname, int id) {
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	f->id = id;
	load_frame(f, pathname);
	return f;
}

void frame_delete(frame_t * f) {
	free(f->content);
	free(f);
}

char* frame_get_content (frame_t *f){
	return f-> content;
}
int frame_get_rep_counter(frame_t * f){
	return f-> rep_counter;
}
int frame_get_id(frame_t *f){
	return f-> id;
}

