#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumSumOfHeights(vector<int> &maxHeights)
	{
		long long res = 0;
		int N = maxHeights.size();
		for (int i = 0; i < N; ++i)
		{
			// choose i as peak
			long long sum = 0;
			sum += maxHeights[i];
			for (int j = i - 1, h = maxHeights[i]; j >= 0; --j)
			{
				h = min(h, maxHeights[j]);
				sum += h;
			}
			for (int j = i + 1, h = maxHeights[i]; j < N; ++j)
			{
				h = min(h, maxHeights[j]);
				sum += h;
			}
			res = max(res, sum);
		}
		return res;
	}
};