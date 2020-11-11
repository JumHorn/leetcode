#include <limits.h>
#include <stdlib.h>

//Definition for an interval.
typedef struct Interval
{
	int start;
	int end;
	struct Interval *next;
} Interval;

typedef struct
{
	int size;
	Interval *data;
} SummaryRanges;

Interval *createNode(int start, int end)
{
	Interval *node = (Interval *)malloc(sizeof(Interval));
	node->start = start;
	node->end = end;
	node->next = NULL;
	return node;
}

/** Initialize your data structure here. */

SummaryRanges *summaryRangesCreate()
{
	SummaryRanges *res = (SummaryRanges *)malloc(sizeof(SummaryRanges));
	res->data = createNode(INT_MIN, INT_MIN);
	res->size = 0;
	return res;
}

void summaryRangesAddNum(SummaryRanges *obj, int val)
{
	Interval *iter;
	for (iter = obj->data; iter->next; iter = iter->next)
	{
		Interval *cur = iter->next;
		if (val < cur->start - 1)
		{
			Interval *newnode = createNode(val, val);
			newnode->next = iter->next;
			iter->next = newnode;
			++obj->size;
			break;
		}
		if (val == cur->start - 1)
		{
			cur->start = val;
			break;
		}
		if (val <= cur->end + 1)
		{
			if (val == cur->end + 1)
				cur->end = val;
			if (cur->next && cur->end + 1 == cur->next->start)
			{
				cur->end = cur->next->end;
				Interval *tmp = cur->next;
				cur->next = cur->next->next;
				free(tmp);
				--obj->size;
			}
			break;
		}
	}
	if (!iter->next)
	{
		iter->next = createNode(val, val);
		++obj->size;
	}
}

int **summaryRangesGetIntervals(SummaryRanges *obj, int *retSize, int **retColSize)
{
	*retSize = obj->size;
	if (*retSize == 0)
		return NULL;
	int **res = (int **)malloc(sizeof(int *) * (*retSize));
	*retColSize = (int *)malloc(sizeof(int) * (*retSize));
	Interval *node = obj->data->next;
	for (int i = 0; i < *retSize; ++i, node = node->next)
	{
		(*retColSize)[i] = 2;
		res[i] = (int *)malloc(sizeof(int) * (*retColSize)[i]);
		res[i][0] = node->start;
		res[i][1] = node->end;
	}
	return res;
}

void summaryRangesFree(SummaryRanges *obj)
{
	Interval *node = obj->data;
	while (node)
	{
		Interval *tmp = node;
		node = node->next;
		free(tmp);
	}
	free(obj);
}