#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumTime(vector<int> &time, int totalTrips)
	{
		long long lo = 0, hi = 1e14;
		while (lo < hi)
		{
			long long mi = (hi - lo) / 2 + lo, trips = 0;
			for (auto t : time)
				trips += mi / t;
			if (trips < totalTrips)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};