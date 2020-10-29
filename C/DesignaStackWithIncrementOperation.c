#include <stdlib.h>

typedef struct
{
	int *stack;
	int top;
	int capacity;
} CustomStack;

CustomStack *customStackCreate(int maxSize)
{
	CustomStack *stack = (CustomStack *)malloc(sizeof(CustomStack));
	stack->capacity = maxSize;
	stack->stack = (int *)malloc(sizeof(int) * stack->capacity);
	stack->top = -1;
	return stack;
}

void customStackPush(CustomStack *obj, int x)
{
	if (obj->top + 1 < obj->capacity)
		obj->stack[++obj->top] = x;
}

int customStackPop(CustomStack *obj)
{
	if (obj->top == -1)
		return -1;
	return obj->stack[obj->top--];
}

void customStackIncrement(CustomStack *obj, int k, int val)
{
	for (int i = 0; i < k && i <= obj->top; ++i)
		obj->stack[i] += val;
}

void customStackFree(CustomStack *obj)
{
	if (obj)
	{
		if (obj->stack)
			free(obj->stack);
		free(obj);
	}
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/