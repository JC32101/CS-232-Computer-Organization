/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "mystring.h"

/* Define what our struct is */
struct mystring_t {
	size_t size;
	char *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new mystring */
mystring_t *bad_string_new() {
	/* Create the string and a pointer to it */
        /*This is a bad constructor as v gets destroyed once contructor returns*/
	mystring_t *retval, v;
	retval = &v;

	/* Initialize attributes */
	retval->size = 1; //why size+1? size is the actual char lenght. 
			  //we must reseve an extra space for null
	retval->data = (char*) malloc((retval->size+1)*sizeof(char));
	if (retval->data == NULL) {
		allocation_failed();
	}

	retval->data[0] = ' ';
	retval->data[retval->size] = '\0';
	return retval;
}

/* Another suboptimal way of creating a string */
mystring_t also_bad_string_new() {
	/* Create the string */
	/*why is this bad? does v get destroyed upon returning? */
	mystring_t s;

	/* Initialize attributes */
	s.size = 1; //why size+1? an extra space for null
	s.data = (char*) malloc((s.size+1)*sizeof(char));
	if (s.data == NULL) {
		allocation_failed();
	}
	s.data[0] = ' ';
	s.data[s.size] = '\0';
	return s;
}

/* Create a new string with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
mystring_t *mystring_new() {
	mystring_t *retval;
	//YOUR CODE HERE
  retval = (mystring_t *)malloc(sizeof(mystring_t));

  if(retval == NULL){
		allocation_failed();
    return NULL;
  }

  retval->size = 1;
  retval->data = (char *)malloc(sizeof(char) * 1);

  if(retval->data == NULL){
		allocation_failed();
    return NULL;
  }

  retval->data[0] = '\0';
	return retval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) {
	//YOUR CODE HERE
  if(loc < s->size && loc >= 0){
    return s->data[loc];
  }
  else{
    perror("out of bound");
    return '\0';
  }
	return ' ';
}

/* Free up the memory allocated for the passed mystring.
   Remember, you need to free up ALL the memory that was allocated. */
void mystring_delete(mystring_t *s) {
	/* YOUR CODE HERE */
  free(s->data);
  free(s);
}

int mystring_get_len(mystring_t *s) {
	/* YOUR CODE HERE */
  return s->size;
}

char* mystring_get_data(mystring_t *s) {
	/* YOUR CODE HERE*/
  // char *str = (char*)malloc(sizeof(s)+1);
  // int i;

  // for(i = 0; i < s->size; i++){
  //   str[i] = s->data[i];
  // }

	return s->data;
}

void mystring_cat(mystring_t *s, char *s2) {
	/* YOUR CODE HERE*/
<<<<<<< HEAD
  char * temp = s->data;
  int i;
  s->data = (char *) malloc(sizeof(char) * sizeof(s2) + 1);
  
  for(i = 0; i < s->size; i++){
    s->data[i] = temp[i];
  }

  for(i = s->size; i < sizeof(s2) + 1; i++){
    mystring_set(s, i, s2[i]);
  }

  free(temp);

  // int size = sizeof(s2), i;
  // // char * temp = s->data;
  // // s->data = (char *) malloc(sizeof(char) * sizeof(s2) + 1);
  // for(i = 0; i < size-2; i++){
  //   s->data[i] = *(s2+i);
  //   // printf("%c", s->data[i]);
  // }

//  size_t j;
//  int t = 0;
//  for(j=0;*(s2+j)!='\0'; j++)
//  j++;
//  s->data = (char*) realloc(s->data, sizeof(char) *(s->size+j));
//  for(int i = s->size; i < (s->size+j); i++){
//    s->data[i]  = *(s2+t);
//    t++;
//  }
//  s->size = s->size+j;
=======
  // char * temp = s->data;
  // int i;
  // s->data = (char *) malloc(sizeof(char) * sizeof(s2) + 1);
  
  // for(i = 0; i < s->size; i++){
  //   s->data[i] = temp[i];
  // }

  // for(i = s->size; i < sizeof(s2) + 1; i++){
  //   mystring_set(s, i, s2[i]);
  // }

  // free(temp);

  int size = sizeof(s2), i;
  // char * temp = s->data;
  // s->data = (char *) malloc(sizeof(char) * sizeof(s2) + 1);
  for(i = 0; i < size-2; i++){
    s->data[i] = s2[i];
    printf("%c", s->data[i]);
  }
>>>>>>> 1ff43bebbdcd977007b02c4062aa8ff808b276d6
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {
	/* YOUR CODE HERE*/
  int i;

  if(loc < s->size && loc >= 0){
    s->data[loc] = value;
  }
  else{
    s->data = (char *)realloc(s->data, sizeof(char) * loc+1);
    
    for(i = s->size; i < loc+1; i++){
      s->data[i] = 0;
    }

    s->data[loc] = value;
    s->size = loc + 1;
  }
	return;
}


int main(int argc, char **argv) {
	mystring_t *s;
	
	printf("Calling mystring_new()\n");
	s = mystring_new();
	
	printf("Calling mystring_delete()\n");
	mystring_delete(s);
	
	printf("mystring_new() again\n");
	s = mystring_new();

	printf("These should all return space (mystring_get()): ");
	printf("%c ", mystring_get(s, 0));
	printf("%c ", mystring_get(s, 1));
	printf("%c\n", mystring_get(s, 2));

	printf("Doing a bunch of mystring_set()s\n");
	mystring_set(s, 0, 'h');
	mystring_set(s, 11, 'a');
	mystring_set(s, 15, 'z');
	mystring_set(s, 24, 'm');
    	mystring_set(s, 500, 's');
	mystring_set(s, 12, 'b');
	mystring_set(s, 25, '!');

	printf("These should be equal:\n");
	printf("h = %c\n", mystring_get(s, 0));
	printf("a = %c\n", mystring_get(s, 11));
	printf("m = %c\n", mystring_get(s, 24));
	printf("b = %c\n", mystring_get(s, 12));
	printf("z = %c\n", mystring_get(s, 15));
	printf("! = %c\n", mystring_get(s, 25));
  printf("  = %c\n", mystring_get(s, 23));
  printf("  = %c\n", mystring_get(s, 1));
  printf("s = %c\n", mystring_get(s, 500));

  // printf("Testing get data: %s\n", mystring_get_data(s));

	if(mystring_get_len(s) == 501) {
		printf("getlen returns 501, success!\n");
	} else {

		printf("getlen does not return 501. Test failed!\n");
	}
	mystring_delete(s);

	s = mystring_new();
	mystring_cat(s, "hello ");
	mystring_cat(s, "world");
	// printf("hello world = %s\n",mystring_get_data(s));
  //       mystring_delete(s);
  // for(int i = 0; i < mystring_get_len(s); i++){
  //   printf("%c", mystring_get(s, i));
  // }
  printf("\n");

	printf("Test complete.\n");
	
	return 0;
}
