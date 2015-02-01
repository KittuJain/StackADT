#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack createStack(void){
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	Stack stack = {list, &list->tail};
	return stack;
}