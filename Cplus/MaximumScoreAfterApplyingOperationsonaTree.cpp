#include <functional>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values)
	{
		int N = values.size();
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		graph[0].push_back(-1); // avoid treating root as leaf node

		function<long long(int, int)> postorder = [&](int at, int from)
		{
			if (graph[at].size() == 1)
				return (long long)values[at];
			long long loss = 0;
			for (auto to : graph[at])
			{
				if (to != from)
					loss += postorder(to, at);
			}
			return min((long long)values[at], loss);
		};

		return accumulate(values.begin(), values.end(), 0LL) - postorder(0, -1);
	}
};