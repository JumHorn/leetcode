#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> secondGreaterElement(vector<int> &nums)
	{
		stack<int> stk;																	   //store index as decreasing stack
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{val,index}
		int N = nums.size();
		vector<int> res(N, -1);
		for (int i = 0; i < N; ++i)
		{
			while (!q.empty() && q.top().first < nums[i])
			{
				res[q.top().second] = nums[i];
				q.pop();
			}
			while (!stk.empty() && nums[stk.top()] < nums[i])
			{
				q.push({nums[stk.top()], stk.top()});
				stk.pop();
			}
			stk.push(i);
		}
		return res;
	}
};