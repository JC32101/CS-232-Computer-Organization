#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
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

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    return head;
}

void teardown(node_t* h) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
    while(head->next != NULL){
      free(head);
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
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
