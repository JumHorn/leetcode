#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int rangeSum(vector<int> &nums, int n, int left, int right)
	{
		//{sum,index of next val add to sum}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		for (int i = 0; i < n; ++i)
			q.push({nums[i], i + 1});
		int res = 0;
		for (int i = 1; i <= right; ++i)
		{
			auto node = q.top();
			q.pop();
			if (i >= left)
				res = (res + node.first) % MOD;
			if (node.second < n)
				q.push({node.first + nums[node.second], node.second + 1});
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};