#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
	{
		int N = vals.size();
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		int res = INT_MIN, index = 0;
		auto f = [&](int lhs, int rhs)
		{ return vals[lhs] > vals[rhs]; };
		for (auto &v : graph)
		{
			sort(v.begin(), v.end(), f);
			int sum = vals[index++];
			for (int i = 0; i < v.size() && i < k && vals[v[i]] > 0; ++i)
				sum += vals[v[i]];
			res = max(res, sum);
		}
		return res;
	}
};