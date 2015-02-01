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
	free(stack.list);
}

void test_push_populates_stack_with_two_integer_elements (){
	Stack stack = createStack();
	int data1 = 10, data2 = 20;
	assertEqual(push(stack, (void*)&data1),1);
	assertEqual(push(stack, (void*)&data2),2);
	free(stack.list);
}

void test_push_populates_stack_with_two_float_elements (){
	Stack stack = createStack();
	float data1 = 10.23, data2 = 2.20;
	assertEqual(push(stack, (void*)&data1),1);
	assertEqual(push(stack, (void*)&data2),2);
	free(stack.list);
}

void test_push_populates_stack_with_two_char_elements (){
	Stack stack = createStack();
	char data1 = 'k', data2 = 'r';
	assertEqual(push(stack, (void*)&data1),1);
	assertEqual(push(stack, (void*)&data2),2);
	free(stack.list);
}

void test_push_populates_stack_with_two_string_elements (){
	Stack stack = createStack();
	String data1 = "Krati";
	String data2 = "Jain";
	assertEqual(push(stack, (void*)&data1),1);
	assertEqual(push(stack, (void*)&data2),2);
	free(stack.list);
}

void test_pop_deletes_an_element_from_the_stack (){
	Stack stack = createStack();
	int data1 = 20;
	push(stack, (void*)&data1);
	assertEqual(*(int*)pop(stack),20);
	assertEqual(stack.list->count, 0);
	free(stack.list);
}

void test_pop_deletes_the_topmost_element_from_the_stack (){
	Stack stack = createStack();
	int data1 = 20, data2 = 21;
	push(stack, (void*)&data1);
	push(stack, (void*)&data2);
	assertEqual(*(int*)pop(stack),21);
	assertEqual(stack.list->count, 1);
	free(stack.list);
}

void test_pop_returns_minus_1_when_there_is_no_element_on_stack (){
	Stack stack = createStack();
	assertEqual(stack.list->count, 0);
	assert((int)pop(stack)==-1);
	assertEqual(stack.list->count, 0);
	free(stack.list);
}