#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		if ((int)nums.size() <= k)
			k = nums.size() - 1;
		unordered_set<int> s;
		for (int i = 0; i <= k; i++)
		{
			if (s.find(nums[i]) != s.end())
				return true;
			s.insert(nums[i]);
		}
		for (int i = k + 1; i < (int)nums.size(); i++)
		{
			s.erase(nums[i - k - 1]);
			if (s.find(nums[i]) != s.end())
				return true;
			s.insert(nums[i]);
		}
		return false;
	}
};
