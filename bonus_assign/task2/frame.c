// /******************************************************
// * File: frame.c
// *
// * This is the frame struct implementation
// *
// ******************************************************/
#include "frame.h"
#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

static void load_frame(frame_t *f, char *path){
	FILE * fp;
  char * line = NULL; 
	fp = fopen(path, "r");
	size_t len = 0;
  size_t read;

  if (fp == NULL){
    exit(EXIT_FAILURE);
  }

  read = getdelim(&line, &len, EOF, fp);
	f->content = (char*)realloc(f->content, len * sizeof(char));
	strcpy(f->content,line);
	f->content[read] = '\0';
	fclose(fp);
	f->rep_counter = (int)f->content[0];
  return;
}

frame_t * frame_new(char *pathname, int id) {
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	f->content = (char *)malloc(sizeof(char));
	f->rep_counter = 0;
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
