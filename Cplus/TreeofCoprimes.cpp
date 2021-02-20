#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
	{
		int N = nums.size();
		vector<vector<pair<int, int>>> graph(N); //{node,value}
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back({edge[1], nums[edge[1]]});
			graph[edge[1]].push_back({edge[0], nums[edge[0]]});
		}
		vector<stack<pair<int, int>>> path(51); // {node,level}
		vector<int> res(N, -1);
		preorder(graph, nums, -1, 0, 0, path, res);
		return res;
	}

	void preorder(vector<vector<pair<int, int>>> &graph, vector<int> &nums, int from, int at, int level, vector<stack<pair<int, int>>> &path, vector<int> &res)
	{
		for (int i = (int)path.size() - 1, l = -1; i > 0; --i)
		{
			if (!path[i].empty() && path[i].top().second > l && gcd(i, nums[at]) == 1)
			{
				l = path[i].top().second;
				res[at] = path[i].top().first;
			}
		}
		for (auto &to : graph[at])
		{
			if (to.first != from)
			{
				path[nums[at]].push({at, level});
				preorder(graph, nums, at, to.first, level + 1, path, res);
				path[nums[at]].pop();
			}
		}
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};