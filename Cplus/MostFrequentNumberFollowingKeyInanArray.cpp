#include <vector>
using namespace std;

class Solution
{
public:
	int mostFrequent(vector<int> &nums, int key)
	{
		vector<int> count(1001);
		int res = 0;
		for (int i = 0; i < (int)nums.size() - 1; ++i)
		{
			if (nums[i] == key)
			{
				++count[nums[i + 1]];
				if (count[nums[i + 1]] > count[res])
					res = nums[i + 1];
			}
		}
		return res;
	}
};