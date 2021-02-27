#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {
    //return NULL;//just to pass compiler, please edit as needed.
    
  node_t *x, *y, *z;
  x = (node_t *)malloc(sizeof(node_t *)*2);
  y = (node_t *)malloc(sizeof(node_t *)*2);
  z = (node_t *)malloc(sizeof(node_t *)*2);
  x->value = "CS232";
  y->value = "is";
  z->value = "awesome";
  x->next = y;
  y->next = z;
  z->next = x;
  return x;
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
      free(x);
      free(y);
      free(z);
    	printf("failed");
    	return -1;
    } else {
        free(x);
        free(y);
        free(z);
        return 0;
    }
}