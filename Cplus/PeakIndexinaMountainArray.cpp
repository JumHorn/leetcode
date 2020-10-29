#include <vector>
using namespace std;

class Solution
{
public:
	int peakIndexInMountainArray(vector<int> &arr)
	{
		int lo = 0, hi = (int)arr.size() - 2;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (arr[mi] < arr[mi + 1])
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};