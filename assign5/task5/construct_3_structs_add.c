#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task1
    node_t * head ;
   
    node_t *node1, *node2, *node3;

    node1 = (node_t *)malloc(sizeof(node_t *));
    node2 = (node_t *)malloc(sizeof(node_t *));
    node3 = (node_t *)malloc(sizeof(node_t *));

    for(int i = 0; i < 6; i++){
        node1->str[i] = "hello\0"[i];
    }

    for(int i = 0; i < 6; i++){
        node2->str[i] = "there\0"[i];   
    }

    for(int i = 0; i < 5; i++){
        node3->str[i] = "prof\0"[i];   
    }

    //head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    head = node1;

    return head;
}

void teardown(node_t* head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
    free(head->next->next->next->next);
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
    node_t *temp;
  
    for(int i = 0; i <= length; i++){
      temp = (node_t *)malloc(sizeof(node_t *));

      for(int i = 0; i < 2; i++){
        temp->str[i] = "hi\0"[i];
      }
    }
      //temp = temp1;
      temp->next = *head;
      *head = temp;
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
