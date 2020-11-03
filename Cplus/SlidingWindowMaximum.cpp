#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

/*
MonoQueue
*/

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		vector<int> res(nums.size() - k + 1);
		deque<int> q;
		for (int i = 0, j = 0; i < (int)nums.size(); ++i)
		{
			while (!q.empty() && nums[q.back()] < nums[i])
				q.pop_back();
			while (!q.empty() && i - k >= q.front())
				q.pop_front();
			q.push_back(i);
			if (i + 1 >= k)
				res[j++] = nums[q.front()];
		}
		return res;
	}
};