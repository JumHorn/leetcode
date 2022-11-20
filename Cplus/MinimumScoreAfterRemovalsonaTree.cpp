#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
	{
		int N = nums.size();
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		//use node 0 as root
		vector<int> XOR(N);
		postorder(graph, nums, 0, -1, XOR);

		//in out timestamps for each node
		vector<int> in(N), out(N);
		int timestamps = 0;
		preorder(graph, 0, -1, timestamps, in, out);

		auto is_parent = [&](int a, int b)
		{
			return in[a] <= in[b] && in[b] <= out[a];
		};

		int all = XOR[0], res = INT_MAX;
		for (int i = 0; i < N - 1; ++i)
		{
			int a = edges[i][0], b = edges[i][1];
			if (!is_parent(a, b))
				swap(a, b);

			for (int j = i + 1; j < N - 1; ++j)
			{
				int c = edges[j][0], d = edges[j][1];
				if (!is_parent(c, d))
					swap(c, d);

				int x = XOR[b], y = XOR[d];
				if (is_parent(b, d))
					x ^= y;
				else if (is_parent(d, b))
					y ^= x;
				int z = all ^ x ^ y;
				res = min(res, max({x, y, z}) - min({x, y, z}));
			}
		}
		return res;
	}

	void preorder(vector<vector<int>> &graph, int at, int from, int &time, vector<int> &in, vector<int> &out)
	{
		in[at] = time;
		for (auto to : graph[at])
		{
			if (to != from)
				preorder(graph, to, at, ++time, in, out);
		}
		out[at] = time;
	}

	int postorder(vector<vector<int>> &graph, vector<int> &nums, int at, int from, vector<int> &XOR)
	{
		int res = nums[at];
		for (auto to : graph[at])
		{
			if (to != from)
				res ^= postorder(graph, nums, to, at, XOR);
		}
		return XOR[at] = res;
	}
};