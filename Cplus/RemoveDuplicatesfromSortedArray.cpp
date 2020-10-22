#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		if (nums.empty())
			return 0;
		int top = 0;
		for (auto n : nums)
		{
			if (n != nums[top])
				nums[++top] = n;
		}
		return top + 1;
	}
};