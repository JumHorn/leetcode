
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray
{
public:
	int get(int index);
	int length();
};

class Solution
{
public:
	int upBinarysearch(int target, MountainArray &m, int lo, int hi)
	{
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int val = m.get(mi);
			if (val == target)
				return mi;
			if (val < target)
				lo = mi + 1;
			else
				hi = mi - 1;
		}
		return -1;
	}

	int downBinarySearch(int target, MountainArray &m, int lo, int hi)
	{
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int val = m.get(mi);
			if (val == target)
				return mi;
			if (val < target)
				hi = mi - 1;
			else
				lo = mi + 1;
		}
		return -1;
	}

	int findInMountainArray(int target, MountainArray &mountainArr)
	{
		int N = mountainArr.length(), lo = 0, peek, hi = N;
		if (hi == 0)
			return -1;
		--hi;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (mountainArr.get(mi) < mountainArr.get(mi + 1))
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
};