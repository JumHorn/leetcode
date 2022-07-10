#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int validSubarraySize(vector<int> &nums, int threshold)
	{
		int N = nums.size();
		vector<int> radius(N, 1);
		stack<int> stk;
		for (int i = 0; i <= N; ++i)
		{
			while (!stk.empty() && (i == N || nums[stk.top()] > nums[i]))
			{
				int index = stk.top();
				stk.pop();
				radius[index] = i - (stk.empty() ? -1 : stk.top()) - 1;
			}
			stk.push(i);
		}

		for (int i = 0; i < N; ++i)
		{
			if (nums[i] > threshold / radius[i])
				return radius[i];
		}
		return -1;
	}
};