#include <cmath>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(vector<int>& nums)
	{
		for (int i = 0; i < (int)nums.size(); i++)
			val_to_index[nums[i]].push_back(i);
	}

	int pick(int target)
	{
		int n = val_to_index[target].size();
		return val_to_index[target][rand() % n];
	}

private:
	map<int, vector<int>> val_to_index;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
