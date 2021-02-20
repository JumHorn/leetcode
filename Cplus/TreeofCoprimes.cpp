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
		vector<pair<int, int>> path;
		vector<int> res(N, -1);
		preorder(graph, nums, -1, 0, path, res);
		return res;
	}

	void preorder(vector<vector<pair<int, int>>> &graph, vector<int> &nums, int from, int at, vector<pair<int, int>> &path, vector<int> &res)
	{
		for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
		{
			if (gcd(iter->second, nums[at]) == 1)
			{
				res[at] = iter->first;
				break;
			}
		}
		for (auto &to : graph[at])
		{
			if (to.first != from)
			{
				path.push_back({at, nums[at]});
				preorder(graph, nums, at, to.first, path, res);
				path.pop_back();
			}
		}
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};