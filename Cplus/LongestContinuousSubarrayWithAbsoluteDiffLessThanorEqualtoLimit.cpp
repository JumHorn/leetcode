#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubarray(vector<int> &nums, int limit)
	{
		deque<int> maxdeque, mindeque;
		int i = 0, j = 0;
		for (; i < (int)nums.size(); ++i)
		{
			while (!maxdeque.empty() && nums[i] > maxdeque.back())
				maxdeque.pop_back();
			maxdeque.push_back(nums[i]);

			while (!mindeque.empty() && nums[i] < mindeque.back())
				mindeque.pop_back();
			mindeque.push_back(nums[i]);
			if (maxdeque.front() - mindeque.front() > limit)
			{
				if (maxdeque.front() == nums[j])
					maxdeque.pop_front();
				if (mindeque.front() == nums[j])
					mindeque.pop_front();
				++j;
			}
		}
		return i - j;
	}
};