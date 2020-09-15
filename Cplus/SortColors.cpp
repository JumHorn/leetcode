#include <vector>
using namespace std;

class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		int count[3] = {0};
		for (auto n : nums)
			++count[n];
		for (int i = 0, j = 0; i < (int)nums.size();)
		{
			if (count[j] > 0)
			{
				--count[j];
				nums[i++] = j;
			}
			else
				++j;
		}
	}
};