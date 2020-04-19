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
		int maxval = INT_MIN, minval = INT_MAX, size = nums.size();
		if (size < 2)
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
		int gap = max(1, interval / (size - 1));
		int bucketnum = interval / gap + 1;
		vector<vector<int>> buckets(bucketnum, vector<int>(2, -1));
		int res = gap;
		for (auto n : nums)
		{
			int index = (n - minval) / gap;
			if (buckets[index][0] == -1)
				buckets[index][0] = buckets[index][1] = n;
			else
			{
				if (n < buckets[index][0])
					buckets[index][0] = n;
				if (n > buckets[index][1])
					buckets[index][1] = n;
			}
		}
		int tmp = buckets[0][1];
		for (int i = 1; i < bucketnum; i++)
		{
			if (buckets[i][0] == -1)
				continue;
			res = max(res, buckets[i][0] - tmp);
			tmp = buckets[i][1];
		}
		return res;
	}
};