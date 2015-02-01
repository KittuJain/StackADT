#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack createStack(void){
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	Stack stack = {list, &list->tail};
	return stack;
}

int push (Stack stack, void* data){
	Node* node = create_node(data);
	int count = add_to_list(stack.list,node);
	return (count < 0) ? -1 : stack.list->count;
}