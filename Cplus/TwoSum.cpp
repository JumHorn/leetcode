#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> m; //{value,index}
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (m.find(target - nums[i]) != m.end())
				return {m[target - nums[i]], i};
			m[nums[i]] = i;
		}
		return {};
	}
};