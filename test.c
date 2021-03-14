// /******************************************************
// * File: frame.c
// *
// * This is the frame struct implementation
// *
// ******************************************************/
#include "frame.h"
#include <stdlib.h>
#define LEN 1200
//_GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>

// static void load_frame(frame_t *f, char *path){
// 	FILE * fp;
//   char * line = NULL; 
// 	fp = fopen(path, "r");
// 	size_t len = 0;
//   size_t read;

//   if (fp == NULL){
//     exit(EXIT_FAILURE);
//   }

//   read = getdelim(&line, &len, EOF, fp);
// 	f->content = (char*)realloc(f->content, len * sizeof(char));
// 	strcpy(f->content,line);
// 	f->content[read] = '\0';
// 	fclose(fp);
// 	f->rep_counter = (int)f->content[0];
//   return;
// }



-----------------------------------------------------------------
-----------------------------------------------------------------
-----------------------------------------------------------------

static void load_frame(frame_t *f, char *path){
  // char *tokenize, *savePtr;
  char fileLine [LEN];
  FILE *fd = fopen(path, "r");
  int m, i;

  if(fd == NULL){
    perror("ERROR OPENING FILE");
  }
  
  printf("Continue to fgets\n");
  
  while(fgets(fileLine, LEN-2, fd) != NULL){

    char *s = (char*)malloc(sizeof(strlen(fileLine)+2));
    for(m = 0; m < strlen(buf); m++){
      *(s+m) = *(buf+m);
    }
    *(s+m-1) = '\0';
    
    if(i == 0){
      f->rep_counter = s[0];
      i++;
    }

    printf("While loop --->\n");
    f->content = (char*)realloc(f->content, strlen(fileLine) * sizeof(char));
    printf("realloced--->\n");
    strcat(f->content,fileLine);
    printf("concat ----> \n content: \n%s\n", f->content);

  }
  fclose(fd);
  
  f->rep_counter = (int)f->content[0];
	return;
}


void frame_set(frame_t* f,  int loc, char* s){
	if((loc < strlen(f->content)) && (loc >= 0)) {
   	f->content[loc] = *s;
  } 
  else {
    f->content = (char*) realloc(f->content, sizeof(char)*strlen(s));

    for(int i = strlen(f->content); i < loc+1; i++)
		  f->content[i] = '\0';
    f->content[loc] = *s;
	}
}


-----------------------------------------------------------------
-----------------------------------------------------------------
-----------------------------------------------------------------


frame_t * frame_new(char *pathname, int id) {
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	f->content = (char *)malloc(sizeof(char));
	f->rep_counter = 0;
	f->id = id;
      printf("Continue to load_frame");

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
