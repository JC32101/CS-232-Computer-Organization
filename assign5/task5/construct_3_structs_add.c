#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
<<<<<<< HEAD
    //TODO:copy setup func from task1
    node_t * head ;
   
    node_t *node1, *node2, *node3;

    node1 = (node_t *)malloc(sizeof(node_t));
    node2 = (node_t *)malloc(sizeof(node_t));
    node3 = (node_t *)malloc(sizeof(node_t));

    strcpy(node1->str, "hello");
    node1->length = 5;
    strcpy(node2->str, "there");
    node2->length = 5;
    strcpy(node3->str, "prof");
    node3->length = 4;

    //head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    head = node1;

    return head;
=======
    //TODO:copy setup func from previous task
>>>>>>> 6d528eb2aaf22713bc34d802db625d3ecc5e1ee6
}

void teardown(node_t *head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
    node_t* finger;

    while(head != NULL){
    finger = head;
    head = head->next;
    free(finger);
    }
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    node_t* cur = *head;
    strcpy(temp->str, str);
    temp->length = length;
    temp->next = cur;
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
