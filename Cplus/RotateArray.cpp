#include <vector>
using namespace std;

class Solution
{
public:
	void rotate(vector<int> &nums, int k)
	{
		int N = nums.size(), start = 0;
		for (int i = 0, index = 0; i < N; ++i)
		{
			index = (index + k) % N;
			if (start == index)
				index = ++start;
			else
				swap(nums[start], nums[index]);
		}
	}
};