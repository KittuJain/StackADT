#include "stack.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void test_createStack_creates_an_empty_stack (){
	Stack new_stack;
	new_stack = createStack();
	assertEqual(new_stack.list->count, 0);
	assert(*new_stack.top == 0);
	free(new_stack.list);
}