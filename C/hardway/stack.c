#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_SIZE 4096

struct Stack {
    int size;
    int top;
    int stack[MAX_SIZE];
};

void die (const char *message)
{
    if (errno){
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void init(struct Stack *stack)
{
    stack->size = 0;
    stack->top = 0;
    int i = 0;
    for(i = 0; i < MAX_SIZE; i++)
        stack->stack[i] = 0;
}

void push(struct Stack *stack, int item)
{
   if (stack->size >= MAX_SIZE - 1){
       die("Stack Overflow!");
   } else {
       stack->stack[stack->size] = item;
       stack->size += 1;
       stack->top = item;
   }
}

void pop(struct Stack *stack)
{
    if (stack->size == 0){
        die("Stack is empty!");
    } else {
        stack->stack[stack->size-1] = 0;
        stack->size -= 1;
        stack->top = stack->stack[stack->size >= 1 ? stack->size-1 : 0];
    }
}

int main(int argc, char *argv[])
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    init(stack);
    push(stack, 0);
    pop(stack);
    free(stack);
    return 0;
}



