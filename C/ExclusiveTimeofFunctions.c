#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Function
{
	int start;
	int end;
	int id;
	int sched;  //schedule time
} Function;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize)
{
	*returnSize = n;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * (*returnSize));
	Function stack[logsSize];
	int top = -1;
	for (int i = 0; i < logsSize; ++i)
	{
		int id, time;
		char state[10];
		sscanf(logs[i], "%d:%[^:]:%d", &id, state, &time);
		stack[top + 1].id = id;
		if (strcmp(state, "start") == 0)
		{
			++top;
			stack[top].start = time;
			stack[top].sched = 0;
		}
		else
		{
			stack[top].end = time;
			time = stack[top].end - stack[top].start + 1;
			res[stack[top].id] += time - stack[top].sched;
			if (top > 0)
				stack[top - 1].sched += time;
			--top;
		}
	}
	return res;
}
