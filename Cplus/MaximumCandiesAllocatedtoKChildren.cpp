#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumCandies(vector<int> &candies, long long k)
	{
		int lo = 1, hi = *max_element(candies.begin(), candies.end()) + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			long long count = 0;
			for (auto n : candies)
				count += n / mi;
			if (count >= k)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}
};