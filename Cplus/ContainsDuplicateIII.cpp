#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

/*
bucket sort
*/

class Solution
{
public:
	bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
	{
		int N = nums.size();
		if (k < 1 || N < 2)
			return false;
		unordered_map<long, long> m;
		for (int i = 0; i < N; ++i)
		{
			long bucket = ((long)nums[i] - INT_MIN) / ((long)t + 1); //map nums[i] to bucket
			if (m.find(bucket) != m.end() || (m.find(bucket - 1) != m.end() && nums[i] - m[bucket - 1] <= t) || (m.find(bucket + 1) != m.end() && m[bucket + 1] - nums[i] <= t))
				return true;
			if (m.size() >= k)
				m.erase(((long)nums[i - k] - INT_MIN) / ((long)t + 1));
			m[bucket] = nums[i];
		}
		return false;
	}
};