#include <limits.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct
{
	int stack[10000][2];  //{value,current min}
	int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate()
{
	MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
	stack->top = 0;
	stack->stack[0][0] = 0;
	stack->stack[0][1] = INT_MAX;
	return stack;
}

void minStackPush(MinStack* obj, int x)
{
	obj->stack[obj->top + 1][1] = min(x, obj->stack[obj->top][1]);
	obj->stack[++obj->top][0] = x;
}

void minStackPop(MinStack* obj)
{
	--obj->top;
}

int minStackTop(MinStack* obj)
{
	return obj->stack[obj->top][0];
}

int minStackGetMin(MinStack* obj)
{
	return obj->stack[obj->top][1];
}

void minStackFree(MinStack* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
