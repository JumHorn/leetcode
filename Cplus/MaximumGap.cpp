#include <climits>
#include <vector>
using namespace std;

/*
buckets sort
*/

class Solution
{
public:
	int maximumGap(vector<int> &nums)
	{
		int maxval = INT_MIN, minval = INT_MAX, N = nums.size();
		if (N < 2)
			return 0;
		for (auto n : nums)
		{
			if (n < minval)
				minval = n;
			if (n > maxval)
				maxval = n;
		}
		int interval = maxval - minval;
		if (interval == 0)
			return 0;
		int gap = max(1, interval / (N - 1));
		int bucketnum = interval / gap + 1;
		vector<pair<int, int>> buckets(bucketnum, {-1, -1}); //{minval,maxval}
		int res = gap;
		for (auto n : nums)
		{
			int index = (n - minval) / gap;
			if (buckets[index].first == -1)
				buckets[index].first = buckets[index].second = n;
			else
			{
				if (n < buckets[index].first)
					buckets[index].first = n;
				if (n > buckets[index].second)
					buckets[index].second = n;
			}
		}
		int prev = buckets[0].second;
		for (int i = 1; i < bucketnum; ++i)
		{
			if (buckets[i].first == -1)
				continue;
			res = max(res, buckets[i].first - prev);
			prev = buckets[i].second;
		}
		return res;
	}
};