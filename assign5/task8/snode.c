#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  struct snode *a = (struct snode*)malloc(sizeof(struct snode));
  a->data = (void*)malloc((strlen(s)+1) * sizeof(s));

  strcpy(a->data, s);
  a->next = NULL;

  return a;
}

void snode_destroy(struct snode * s) 
{
  free(s->data);
  free(s);
}
