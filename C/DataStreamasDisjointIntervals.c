#include <stdlib.h>
#include <limits.h>

//Definition for an interval.
struct Interval
{
	int start;
	int end;
	struct Interval *next;
};

typedef struct Interval Interval;

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
	res->data = (Interval *)malloc(sizeof(Interval));
	res->data->start = INT_MIN;
	res->data->end = INT_MIN;
	res->size = 0;
	return res;
}

void summaryRangesAddNum(SummaryRanges *obj, int val)
{
	if (obj->size == 0)
	{
		++obj->size;
		obj->data->next = createNode(val, val);
		return;
	}
	Interval *iter;
	for (iter = obj->data; iter->next; iter = iter->next)
	{
		Interval *curr = iter->next;
		if (val < curr->start - 1)
		{
			Interval *newnode = createNode(val, val);
			newnode->next = iter->next;
			iter->next = newnode;
			++obj->size;
			break;
		}
		if (val == curr->start - 1)
		{
			curr->start = val;
			break;
		}
		if (val <= curr->end + 1)
		{
			if (val == curr->end + 1)
				curr->end = val;
			if (curr->next && curr->end + 1 == curr->next->start)
			{
				curr->end = curr->next->end;
				Interval *tmp = curr->next;
				curr->next = curr->next->next;
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
	int size = obj->size;
	*retSize = size;
	if (size == 0)
		return NULL;
	*retColSize = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		(*retColSize)[i] = 2;
	int **res = (int **)malloc(sizeof(int *) * size);
	Interval *root = obj->data->next;
	for (int i = 0; i < size; i++, root = root->next)
	{
		res[i] = (int *)malloc(sizeof(int) * 2);
		res[i][0] = root->start;
		res[i][1] = root->end;
	}
	return res;
}

void summaryRangesFree(SummaryRanges *obj)
{
	Interval *root = obj->data;
	while (root)
	{
		Interval *tmp = root;
		root = root->next;
		free(tmp);
	}
	free(obj);
}