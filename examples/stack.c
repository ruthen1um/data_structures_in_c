#include <stdio.h>

#include "ds.h"

void print_data(DataStruct data_s) {
    switch (data_s.type) {
        case IntegerType:
            printf("data: %d\n", data_s.i);
            break;
        case FloatType:
            printf("data: %f\n", data_s.f);
            break;
        default:
            printf("Error");
            break;
    }
}

int main(void) {
    Stack *stack = stack_create();

    for (int i = 1; i < 10; ++i) {
        DataStruct data_s = { .type = IntegerType, .i = i };
        stack_push(stack, data_s);
    }

    stack_push(stack, (DataStruct){ .type = FloatType, .f = 321.123 });
    stack_pop(stack);

    stack_for_each(stack, print_data);

    stack_destroy(stack);
}
