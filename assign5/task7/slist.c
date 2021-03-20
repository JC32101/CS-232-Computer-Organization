#include <stdio.h>
#include "slist.h"
#include <string.h>
#include <stdlib.h>

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create(){
  struct slidt *head = (struct slist*)malloc(sizeof(struct slist));
  head->front = NULL;
  head->back = NULL;
  return head;
}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, char *str){
  struct snode* temp = snode_create(str);
  if(l->front == NULL){
    l->front = temp;
    l->back = temp;
  }
  else{
    l->back->next = temp;
    l->back = temp;
  }
  return temp;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str){
  struct snode* temp = snode_create(str);
  if(l->front == NULL){
    l->front = temp;
    l->back = temp;
  }
  else{
    temp->next = l->front;
    l->front = temp;
  }
  return temp;
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str){
  struct snode *temp = l->front;
  while(temp != NULL){
    if(strcmp(temp->str, str) == 0){
      return temp;
    }
    else{
      temp = temp->next;
    }
  }
  return NULL;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){
  struct snode *cur = l->front;
  struct snode *temp;
  while(cur != NULL){
    temp = node->next;
    snode_destroy(node);
    node = temp;
  }
  free(l);
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
  struct snode *cur = l->front;
  while(cur != NULL){
    printf("%s\n", cur->str);
    cur = cur->next;
  }
}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
  struct snode *cur = l->front;
  int length = 0;
  while(cur != NULL){
    length++;
    cur = cur->next;
  }
  return (uint32_t)length;
}
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, char *str){
  struct snode *cur = l->front;
  struct snode *temp;
  while(cur != NULL){
    if(strcmp(cur->str, str) == 0){
      temp->next = temp->next->next;
      snode_destroy(cur);
      return;
    }
  }
}