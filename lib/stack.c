#include <stdlib.h>
#include "stack.h"

Stack *stack_create() {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_destroy(Stack *stack) {
    for (StackNode *current = stack->top, *tmp; current != NULL; current = tmp) {
        tmp = current->next;
        free(current);
    }
    free(stack);
}

void stack_push(Stack *stack, DataStruct data_s) {
    StackNode *node = malloc(sizeof(StackNode));

    node->next = stack->top;
    node->data_s = data_s;
    stack->top = node;
    stack->size++;
}

DataStruct stack_pop(Stack *stack) {
    StackNode *tmp = stack->top->next;
    DataStruct data_s = stack->top->data_s;
    free(stack->top);
    stack->top = tmp;
    return data_s;
}

void stack_for_each(Stack *stack, void (*callback)(DataStruct data_s)) {
    for (StackNode *current = stack->top; current != NULL; current = current->next) {
        callback(current->data_s);
    }
}
