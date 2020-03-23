#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	bool find132pattern(vector<int>& nums)
	{
		if (nums.empty())
			return false;
		stack<pair<int, int>> s;
		int lo = nums[0];
		for (int i = 1; i < (int)nums.size(); i++)
		{
			if (nums[i] <= lo)
				lo = nums[i];
			else
			{
				while (!s.empty())
				{
					if (nums[i] <= s.top().first)
						break;
					if (nums[i] < s.top().second)
						return true;
					s.pop();
				}
				s.push({lo, nums[i]});
			}
		}
		return false;
	}
};
