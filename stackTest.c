#include "stack.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void test_createStack_creates_an_empty_stack (){
	Stack stack;
	stack = createStack();
	assertEqual(stack.list->count, 0);
	assert(*stack.top == 0);
	free(stack.list);
}

void test_push_populates_stack_with_an_integer_element (){
	Stack stack = createStack();
	int data = 10;
	assertEqual(push(stack, (void*)&data),1);
}
