#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumScore(vector<int> &scores, vector<vector<int>> &edges)
	{
		int N = scores.size();
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		for (auto &v : graph)
		{
			sort(v.begin(), v.end(), [&](int lhs, int rhs)
				 { return scores[lhs] > scores[rhs]; });
		}
		int res = -1;
		auto count = [&](int a, int b, int c, int d)
		{
			return !(b == a || c == a || c == b || d == a || d == b || d == c);
		};
		for (auto &edge : edges)
		{
			int u = edge[0], v = edge[1];
			for (int i = 0; i < 4 && i < (int)graph[u].size(); ++i)
			{
				int a = graph[u][i];
				for (int j = 0; j < 4 && j < (int)graph[v].size(); ++j)
				{
					int b = graph[v][j];
					if (count(u, v, a, b))
						res = max(res, scores[u] + scores[v] + scores[a] + scores[b]);
				}
			}
		}
		return res;
	}
};