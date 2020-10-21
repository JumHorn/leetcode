#include <stdlib.h>

//DynamicArray
typedef struct DynamicArray
{
	int *data;
	int size;
	int capacity;
} DynamicArray;

DynamicArray *arr_init()
{
	DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
	arr->size = 0;
	arr->capacity = 4;
	arr->data = (int *)malloc(sizeof(int) * arr->capacity);
	return arr;
}

void arr_append(DynamicArray *arr, int val)
{
	if (arr->size >= arr->capacity)
	{
		arr->capacity <<= 1;
		arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
	}
	arr->data[arr->size++] = val;
}
/********end of DynamicArray********/

typedef struct
{
	DynamicArray **arrId;	//store snapshot id
	DynamicArray **arrValue; //store snapshot value
	int arrSize;
	int snapid; //0 based
} SnapshotArray;

SnapshotArray *snapshotArrayCreate(int length)
{
	SnapshotArray *res = (SnapshotArray *)malloc(sizeof(SnapshotArray));
	res->arrSize = length;
	res->arrId = (DynamicArray **)malloc(sizeof(DynamicArray *) * length);
	res->arrValue = (DynamicArray **)malloc(sizeof(DynamicArray *) * length);
	for (int i = 0; i < length; ++i)
	{
		res->arrId[i] = arr_init();
		arr_append(res->arrId[i], 0);
		res->arrValue[i] = arr_init();
		arr_append(res->arrValue[i], 0);
	}
	res->snapid = 0;
	return res;
}

void snapshotArraySet(SnapshotArray *obj, int index, int val)
{
	arr_append(obj->arrId[index], obj->snapid);
	arr_append(obj->arrValue[index], val);
}

int snapshotArraySnap(SnapshotArray *obj)
{
	return obj->snapid++;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id)
{
	int lo = 0, hi = obj->arrId[index]->size;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (obj->arrId[index]->data[mi] <= snap_id)
			lo = mi + 1;
		else
			hi = mi;
	}
	return obj->arrValue[index]->data[lo - 1];
}

void snapshotArrayFree(SnapshotArray *obj)
{
	if (obj)
	{
		for (int i = 0; i < obj->arrSize; ++i)
		{
			free(obj->arrId[i]);
			free(obj->arrValue[i]);
		}
		free(obj);
	}
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);

 * int param_2 = snapshotArraySnap(obj);

 * int param_3 = snapshotArrayGet(obj, index, snap_id);

 * snapshotArrayFree(obj);
*/