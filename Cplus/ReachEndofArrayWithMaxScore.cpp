#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	long long findMaximumScore(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		stack<int> s; // store index
		s.push(0);
		for (int i = 0; i < N - 1; ++i)
		{
			if (nums[i] > nums[s.top()])
				s.push(i);
		}
		long long j = N - 1;
		for (; !s.empty(); s.pop())
		{
			res += (j - s.top()) * nums[s.top()];
			j = s.top();
		}
		return res;
	}
};