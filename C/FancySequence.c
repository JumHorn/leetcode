#include <stdlib.h>

static const int MOD = 1e9 + 7;

long power(long x, int y)
{
	long res = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
	}
	return res;
}

typedef struct
{
	long data[100000];
	int dataSize;
	long mul, add;
} Fancy;

Fancy *fancyCreate()
{
	Fancy *fancy = (Fancy *)malloc(sizeof(Fancy));
	fancy->dataSize = fancy->add = 0;
	fancy->mul = 1;
	return fancy;
}

void fancyAppend(Fancy *obj, int val)
{
	val = ((val - obj->add) % MOD + MOD) % MOD;
	val = (val * power(obj->mul, MOD - 2)) % MOD;
	obj->data[obj->dataSize++] = val;
}

void fancyAddAll(Fancy *obj, int inc)
{
	obj->add = (obj->add + inc) % MOD;
}

void fancyMultAll(Fancy *obj, int m)
{
	obj->mul = (obj->mul * m) % MOD;
	obj->add = (obj->add * m) % MOD;
}

int fancyGetIndex(Fancy *obj, int idx)
{
	if (idx >= obj->dataSize)
		return -1;
	return (obj->data[idx] * obj->mul + obj->add) % MOD;
}

void fancyFree(Fancy *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Fancy struct will be instantiated and called as such:
 * Fancy* obj = fancyCreate();
 * fancyAppend(obj, val);

 * fancyAddAll(obj, inc);

 * fancyMultAll(obj, m);

 * int param_4 = fancyGetIndex(obj, idx);

 * fancyFree(obj);
*/