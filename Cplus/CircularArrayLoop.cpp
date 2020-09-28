#include <vector>
using namespace std;

class Solution
{
public:
	bool circularArrayLoop(vector<int> &nums)
	{
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == 0)
				continue;
			// slow/fast pointer
			int head = nums[i];
			int slow = i, fast = next(nums, i);
			while (nums[fast] * head > 0 && nums[next(nums, fast)] * head > 0)
			{
				if (slow == fast)
				{
					// check for loop with only one element(possible 0)
					if (slow == next(nums, slow))
						break;
					return true;
				}
				slow = next(nums, slow);
				fast = next(nums, next(nums, fast));
			}
			// loop not found, set all element along the way to 0
			slow = i;
			while (nums[slow] * head > 0)
			{
				fast = next(nums, slow);
				nums[slow] = 0;
				slow = fast;
			}
		}
		return false;
	}

	int next(vector<int> &nums, int index)
	{
		int N = nums.size();
		return (nums[index] % N + index + N) % N;
	}
};