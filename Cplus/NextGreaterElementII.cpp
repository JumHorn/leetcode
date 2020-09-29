#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		int N = nums.size();
		stack<int> s;
		vector<int> res(N, -1);
		for (int i = 0; i < 2 * N; ++i)
		{
			while (!s.empty() && nums[s.top()] < nums[i % N])
			{
				res[s.top()] = nums[i % N];
				s.pop();
			}
			s.push(i % N);
		}
		return res;
	}
};