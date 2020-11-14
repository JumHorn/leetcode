#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct RangeModule
{
	int left;
	int right;
	struct RangeModule *next;
} RangeModule;

RangeModule *createModule(int left, int right)
{
	RangeModule *rangemodule = (RangeModule *)malloc(sizeof(RangeModule));
	rangemodule->left = left;
	rangemodule->right = right;
	rangemodule->next = NULL;
	return rangemodule;
}

RangeModule *rangeModuleCreate()
{
	//first node as dummy node
	return createModule(INT_MIN, INT_MIN);
}

RangeModule *lower_bound(RangeModule *obj, int val)
{
	while (obj->next && obj->next->left < val)
		obj = obj->next;
	return obj;
}

void rangeModuleAddRange(RangeModule *obj, int left, int right)
{
	obj = lower_bound(obj, left);
	RangeModule *node = createModule(left, right);
	node->next = obj->next;
	obj->next = node;
	if (obj->right < left)
		obj = obj->next;
	while (obj->next && obj->right >= obj->next->left)
	{
		obj->right = max(obj->right, obj->next->right);
		obj->next = obj->next->next;
	}
}

bool rangeModuleQueryRange(RangeModule *obj, int left, int right)
{
	obj = lower_bound(obj, left);
	return ((obj->next && obj->next->left <= left && obj->next->right >= right) ||
			(obj->right >= right));
}

void rangeModuleRemoveRange(RangeModule *obj, int left, int right)
{
	obj = lower_bound(obj, left);
	if (obj->right > right)
	{
		RangeModule *node = createModule(right, obj->right);
		node->next = obj->next;
		obj->next = node;
	}
	obj->right = min(obj->right, left);
	while (obj->next && obj->next->right <= right)
		obj->next = obj->next->next;
	if (obj->next)
		obj->next->left = max(obj->next->left, right);
}

void rangeModuleFree(RangeModule *obj)
{
	while (obj)
	{
		RangeModule *deletenode = obj;
		obj = obj->next;
		free(deletenode);
	}
}

/**
 * Your RangeModule struct will be instantiated and called as such:
 * RangeModule* obj = rangeModuleCreate();
 * rangeModuleAddRange(obj, left, right);

 * bool param_2 = rangeModuleQueryRange(obj, left, right);

 * rangeModuleRemoveRange(obj, left, right);

 * rangeModuleFree(obj);
*/