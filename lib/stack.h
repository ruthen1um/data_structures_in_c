#ifndef STACK_H
#define STACK_H

#include "data.h"

typedef struct StackNode {
    DataStruct data_s;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
    unsigned int size;
} Stack;

Stack *stack_create();
void stack_destroy(Stack *stack);

void stack_push(Stack *stack, DataStruct data_s);
DataStruct stack_pop(Stack *stack);

void stack_for_each(Stack *stack, void (*callback)(DataStruct data_s));

#endif
