#include <algorithm>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	long long findMaximumElegance(vector<vector<int>> &items, int k)
	{
		unsigned long long res = 0, profit = 0, N = items.size();
		sort(items.begin(), items.end(), [](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[0] > rhs[0]; });
		unordered_set<int> seen;
		stack<int> stk;
		for (int i = 0; i < N; ++i)
		{
			if (i < k)
			{
				profit += items[i][0];
				if (seen.count(items[i][1]))
					stk.push(items[i][0]);
			}
			else if (seen.find(items[i][1]) == seen.end())
			{
				if (stk.empty())
					break;
				profit = profit - stk.top() + items[i][0];
				stk.pop();
			}
			seen.insert(items[i][1]);
			res = max(res, profit + seen.size() * seen.size());
		}
		return res;
	}
};