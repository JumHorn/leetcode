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
		vector<vector<int>> data(51); // {node,index}
		vector<int> res(N, -1);
		postorder(graph, nums, -1, 0, data, res);
		return res;
	}

	void postorder(vector<vector<pair<int, int>>> &graph, vector<int> &nums, int from, int at, vector<vector<int>> &data, vector<int> &res)
	{
		int N = data.size();
		for (auto &to : graph[at])
		{
			if (to.first != from)
			{
				vector<vector<int>> next_data(N);
				postorder(graph, nums, at, to.first, next_data, res);
				for (int i = 1; i < N; ++i)
				{
					for (auto n : next_data[i])
						data[i].push_back(n);
				}
			}
		}
		for (int i = 1; i < N; ++i)
		{
			if (gcd(i, nums[at]) == 1)
			{
				for (auto n : data[i])
					res[n] = at;
				data[i].clear();
			}
		}
		data[nums[at]].push_back(at);
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};