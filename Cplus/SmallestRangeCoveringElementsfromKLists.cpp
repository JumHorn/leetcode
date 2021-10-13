#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> smallestRange(vector<vector<int>> &nums)
	{
		//{row,col}
		auto f = [&](pair<int, int> &lhs, pair<int, int> &rhs)
		{
			return nums[lhs.first][lhs.second] > nums[rhs.first][rhs.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);
		int N = nums.size(), maxval = INT_MIN;
		for (int i = 0; i < N; ++i)
		{
			maxval = max(maxval, nums[i][0]);
			q.push({i, 0});
		}
		int minval = nums[q.top().first][q.top().second], range = maxval - minval;
		vector<int> res = {minval, maxval};
		while (q.top().second + 1 < (int)nums[q.top().first].size())
		{
			auto ele = q.top();
			q.pop();
			maxval = max(maxval, nums[ele.first][++ele.second]);
			q.push(ele);
			minval = nums[q.top().first][q.top().second];
			if (maxval - minval < range)
			{
				range = maxval - minval;
				res = {minval, maxval};
			}
		}
		return res;
	}
};