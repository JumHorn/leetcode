/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 */

typedef struct MountainArray MountainArray;
int get(MountainArray *, int index);
int length(MountainArray *);

int upBinarysearch(int target, MountainArray *m, int lo, int hi)
{
	while (lo <= hi)
	{
		int mi = (hi - lo) / 2 + lo;
		int val = get(m, mi);
		if (val == target)
			return mi;
		if (val < target)
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	return -1;
}

int downBinarySearch(int target, MountainArray *m, int lo, int hi)
{
	while (lo <= hi)
	{
		int mi = (hi - lo) / 2 + lo;
		int val = get(m, mi);
		if (val == target)
			return mi;
		if (val < target)
			hi = mi - 1;
		else
			lo = mi + 1;
	}
	return -1;
}

int findInMountainArray(int target, MountainArray *mountainArr)
{
	int N = length(mountainArr), lo = 0, peek, hi = N;
	if (hi == 0)
		return -1;
	--hi;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (get(mountainArr, mi) < get(mountainArr, mi + 1))
			lo = mi + 1;
		else
			hi = mi;
	}
	peek = lo;
	int res = upBinarysearch(target, mountainArr, 0, peek);
	if (res != -1)
		return res;
	return downBinarySearch(target, mountainArr, peek + 1, N - 1);
}