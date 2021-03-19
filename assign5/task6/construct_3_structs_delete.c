#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task2
    node_t * head ; 
    node_t *node1, *node2, *node3;

    node1 = (node_t *)malloc(sizeof(node_t *));
    node2 = (node_t *)malloc(sizeof(node_t *));
    node3 = (node_t *)malloc(sizeof(node_t *));

    strcpy(node1->str, "hello");
    node1->length = 5;
    strcpy(node2->str, "there");
    node2->length = 5;
    strcpy(node3->str, "prof");
    node3->length = 4;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    head = node1;

    return head;
}

void teardown(node_t *head) {
  node_t* finger;
  while(head != NULL){
    finger = head;
    head = head->next;
    free(finger);
  }
}

void add(node_t ** head, char * str, int length){
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  node_t* cur = *head;
  strcpy(temp->str, str);
  temp->length = length;
  temp->next = cur;
  *head = temp;
}

void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
  node_t *finger = *head;
  node_t *temp = NULL;
  if(idx == 0){
    *head = finger->next;
    free(finger);
  }
  else{
    for(int i = 0; i < idx; i++){
      if(i == idx-1){
        temp->next = temp->next->next;
        free(finger);
        return;
      }
      else{
        temp = finger;
        finger = finger->next;
      }
    }
  }
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
  node_t *finger = *head;
  node_t *temp = NULL;

  while(finger != NULL){
    if(strcmp(finger->str, key) == 0){
      temp->next = temp->next->next;
      free(finger);
      return;
    }
    else{
      temp = finger;
      finger = finger->next;
    }
  }
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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
