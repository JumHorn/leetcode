#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkSubarraySum(vector<int> &nums, int k)
	{
		unordered_map<int, int> m; //{remainder,index}
		int sum = 0, N = nums.size();
		m[0] = -1;
		for (int i = 0; i < N; ++i)
		{
			sum += nums[i];
			if (k != 0)
				sum %= k;
			auto it = m.find(sum);
			if (it != m.end())
			{
				if (i - it->second > 1)
					return true;
			}
			m.insert({sum, i});
		}
		return false;
	}
};