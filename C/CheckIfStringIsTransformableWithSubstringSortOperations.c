#include <stdbool.h>
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

bool isTransformable(char *s, char *t)
{
	DynamicArray *pos[10];
	for (int i = 0; i < 10; ++i)
		pos[i] = arr_init();
	int used[10] = {0}; //used index of pos
	for (int i = 0; s[i]; ++i)
		arr_append(pos[s[i] - '0'], i);
	for (int i = 0; t[i]; ++i)
	{
		int c = t[i] - '0';
		if (used[c] >= pos[c]->size)
			return false;
		for (int j = 0; j < c; ++j)
		{
			if (used[j] < pos[j]->size && pos[j]->data[used[j]] < pos[c]->data[used[c]])
				return false;
		}
		++used[c];
	}
	return true;
}