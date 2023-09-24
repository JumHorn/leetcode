#include <vector>
using namespace std;

class Solution
{
public:
	long long countPaths(int n, vector<vector<int>> &edges)
	{
		long long res = 0;
		vector<vector<int>> graph(n + 1);
		for (auto edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		postorder(graph, 1, -1, res);
		return res;
	}

	//{zero primer count,only one primer count}
	pair<int, int> postorder(vector<vector<int>> &graph, int at, int from, long long &num)
	{
		pair<int, int> res;
		bool p = isPrimer(at);
		if (p)
			res.second = 1;
		else
			res.first = 1;

		for (auto to : graph[at])
		{
			if (to != from)
			{
				auto val = postorder(graph, to, at, num);
				num += (long long)val.second * res.first;
				num += (long long)val.first * res.second;
				if (p)
				{
					res.second += val.first;
				}
				else
				{
					res.first += val.first;
					res.second += val.second;
				}
			}
		}
		return res;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (long long i = 2; i * i <= N; ++i)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
};