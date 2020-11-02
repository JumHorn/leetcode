#include <vector>
using namespace std;

class Solution
{
public:
	int findKthPositive(vector<int> &arr, int k)
	{
		int N = arr.size();
		int lo = 0, hi = N;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (arr[mi] - mi - 1 < k)
				lo = mi + 1;
			else
				hi = mi;
		}
		if (--lo < 0)
			return k;
		return arr[lo] + k - (arr[lo] - lo - 1);
	}
};