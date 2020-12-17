#include <cmath>
#include <vector>
using namespace std;

/*
Algorithm:
Reservoir Sampling
*/

class Solution
{
public:
	Solution(vector<int> &nums) : data(nums)
	{
	}

	int pick(int target)
	{
		int count = 0, res = 0;
		for (int i = 0; i < (int)data.size(); ++i)
		{
			if (data[i] == target)
			{
				if (rand() % ++count == 0)
					res = i;
			}
		}
		return res;
	}

private:
	vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
