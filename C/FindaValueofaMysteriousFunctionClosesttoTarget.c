
#define min(a, b) (((a) < (b)) ? (a) : (b))

int func(int* arr, int l, int r)
{
	if (r < l)
		return -1e9;
	int res = arr[l];
	for (int i = l + 1; i <= r; ++i)
		res &= arr[i];
	return res;
}

int closestToTarget(int* arr, int arrSize, int target)
{
	int res = target + 1e9;
	for (int i = 0; i < arrSize; ++i)
	{
		int val = func(arr, i, arrSize - 1);
		if (val >= target)
			res = min(res, val - target);
		else if (arr[i] <= target)
			res = min(res, target - arr[i]);
		else
		{
			//binary search
			int lo = i, hi = arrSize;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				val = func(arr, i, mi);
				if (val >= target)
					lo = mi + 1;
				else
					hi = mi;
			}
			val = func(arr, i, lo - 1);
			res = min(res, val - target);
			val = func(arr, i, lo);
			res = min(res, target - val);
		}
	}
	return res;
}
