#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minEatingSpeed(vector<int> &piles, int H)
	{
		int lo = 1, hi = 1e9;
		while (lo < hi)
		{
			int mi = lo + (hi - lo) / 2;
			if (timeToEatAll(piles, mi) > H)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	int timeToEatAll(vector<int> &piles, int k)
	{
		int hour = 0;
		for (auto pile : piles)
			hour += (pile - 1) / k + 1;
		return hour;
	}
};