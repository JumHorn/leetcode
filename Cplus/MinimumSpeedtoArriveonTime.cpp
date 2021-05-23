#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSpeedOnTime(vector<int> &dist, double hour)
	{
		int N = dist.size();
		int lo = 1, hi = 1e9;
		if (N - 1 + dist.back() * 1.0 / hi > hour)
			return -1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			double h = 0;
			for (int i = 0; i < N - 1; ++i)
				h += dist[i] / mi + (dist[i] % mi == 0 ? 0 : 1);
			h += dist[N - 1] * 1.0 / mi;
			if (h > hour)
				lo = mi + 1;
			else
				hi = mi;
		}
		return hi;
	}
};