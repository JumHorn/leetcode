#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canPartition(vector<int> &nums)
	{
		int N = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		sort(nums.begin(), nums.end(), greater<int>());
		if (nums.front() * 2 > sum)
			return false;
		unordered_set<int> diff;
		diff.insert(0);
		for (auto n : nums)
		{
			unordered_set<int> next_diff;
			if (diff.find(sum) != diff.end())
				return true;
			for (auto d : diff)
			{
				if (d > sum)
					continue;
				next_diff.insert(abs(d - n));
				next_diff.insert(d + n);
			}
			diff = next_diff;
			sum -= n;
		}
		return diff.find(0) != diff.end();
	}
};