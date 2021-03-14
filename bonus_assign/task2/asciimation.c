/******************************************************
* File: asciimation.c
*
* This is implementation of asciimation
*
******************************************************/
#include "asciimation.h"
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_num_frames(char *path) {
	DIR * dir = opendir(path);
	struct dirent * pdir;
  int n = 0;

  if(dir == NULL){
    printf("Cannot open directory '%s'\n", path);
    return 1;
  }
  else{
    while((pdir = readdir(dir))) {
      if(strcmp(pdir->d_name, ".") != 0 && strcmp(pdir->d_name, "..") != 0) {
        n++;
      }
		}
    closedir(dir);
  }

	return n;
}

asciimation_t * asciimation_new(char * path, int fps){
	asciimation_t * ascm = (asciimation_t *) malloc(sizeof(asciimation_t));
	if(!ascm) {
		perror("failed allocation\n");
		return 0;
	}

	int n = get_num_frames(path);

	ascm->frames = vector_new(n);

	for(int i=0; i<n; i++) {
		char asciipath[4096];
		strcpy(asciipath, path);
		int len = strlen(asciipath);
		if(asciipath[len-1] != '/') 
			sprintf(asciipath+len, "/%d", i+1);
		else
			sprintf(asciipath+len, "%d", i+1);
		struct frame_t * frame = frame_new(asciipath,i);
		vector_set(ascm->frames, i, frame);
	}
  
	return ascm;
}

void asciimation_delete(asciimation_t * ascm){
  vector_delete(ascm->frames);
	free(ascm);
}

void asciimation_play(asciimation_t * ascm){
  for(int i=0; i < ascm->frames->size; ++i) {
		printf("%s",vector_get_frame_content(ascm->frames, i));
	  sleep(ascm->frames_per_second * vector_get_frame_rep_counter(ascm->frames, i));
  }
}

void asciimation_reverse(asciimation_t * ascm){
  for(int i = ascm->frames->size; i > 0; --i) {
		printf("%s",vector_get_frame_content(ascm->frames, i-1));
		sleep(ascm->frames_per_second * vector_get_frame_rep_counter(ascm->frames, i-1));
	}
}