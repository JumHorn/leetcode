#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkSubarraySum(vector<int> &nums, int k)
	{
		unordered_map<int, int> m; //{value,index}
		int sum = 0;
		m[0] = -1;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			sum += nums[i];
			if (k != 0)
				sum %= k;
			if (m.find(sum) != m.end())
			{
				if (i - m[sum] > 1)
					return true;
			}
			m.insert({sum, i});
		}
		return false;
	}
};