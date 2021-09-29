#include <vector>
using namespace std;

/*
交换总次数是由N控制的，一共只需交换N次
*/

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