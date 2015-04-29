#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int min(int a1, int a2){
    return a1 < a2 ? a1 : a2;
}

typedef struct {
    int* num_stack;
    int* min_stack;
    int  maxSize;
    int  pos;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->num_stack = (int*)malloc(sizeof(int)*maxSize);
    stack->min_stack = (int*)malloc(sizeof(int)*maxSize);
    stack->maxSize = maxSize;
    stack->pos = -1;
}

void minStackPush(MinStack *stack, int element) {
    stack->pos += 1;
    stack->num_stack[stack->pos] = element;
    stack->min_stack[stack->pos] = stack->pos == 0 ? element : min(element, stack->min_stack[stack->pos-1]);
}

void minStackPop(MinStack *stack) {
    stack->pos -= 1;
}

int minStackTop(MinStack *stack) {
    return stack->num_stack[stack->pos];
}

int minStackGetMin(MinStack *stack) {
    return stack->min_stack[stack->pos];   
}

void minStackDestroy(MinStack *stack) {
    stack->pos = -1;
}

int main(){
    printf("%d\n", 199);
    return 0;
}