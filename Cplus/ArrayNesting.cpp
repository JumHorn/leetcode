#include <algorithm>
#include <vector>
using namespace std;

/*
there is always a circle in this array
*/

class Solution
{
public:
	int arrayNesting(vector<int> &nums)
	{
		int res = 0;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (nums[i] == -1)
				continue;
			int index = i, count = 0;
			while (nums[index] != -1)
			{
				++count;
				int next = nums[index];
				nums[index] = -1;
				index = next;
			}
			res = max(res, count);
		}
		return res;
	}
};