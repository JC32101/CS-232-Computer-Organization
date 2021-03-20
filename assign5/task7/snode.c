#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>
typedef struct snode node_t;

struct snode *snode_create(char *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  node_t *node1 = (node_t*)malloc(sizeof(node_t));
  node1->data = (char*)malloc(sizeof(char)*strlen(s)+1);
  strcpy(node1->data, s);
  node1->next = NULL;

  return node1;

}

void snode_destroy(struct snode * s) 
{
 //TODO: implement snode_destroy
  node_t *temp;
  while(s!=NULL){
          temp = s;
          s = s->next;
          free(temp);
  }
 
};
 