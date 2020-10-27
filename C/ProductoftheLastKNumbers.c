#include <stdlib.h>

typedef struct
{
	int prefix[40000];
	int size;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate()
{
	ProductOfNumbers* res = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
	res->prefix[0] = 1;
	res->size = 1;
	return res;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num)
{
	if (num == 0)
		obj->size = 1;
	else
		obj->prefix[obj->size++] = obj->prefix[obj->size - 1] * num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k)
{
	return k >= obj->size ? 0 : obj->prefix[obj->size - 1] / obj->prefix[obj->size - k - 1];
}

void productOfNumbersFree(ProductOfNumbers* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
