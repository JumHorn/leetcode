#include <vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int size = 0;
		for (auto n : nums)
		{
			if (n != val)
				nums[size++] = n;
		}
		return size;
	}
};