#include <vector>
using namespace std;

class Solution
{
public:
	int waysToBuildRooms(vector<int> &prevRoom)
	{
		int N = prevRoom.size();
		vector<vector<int>> graph(N);
		for (int i = 1; i < N; ++i)
			graph[prevRoom[i]].push_back(i);
		return postorder(graph, 0, -1).second;
	}
	//{node count,combinations for subtree}
	pair<int, long> postorder(vector<vector<int>> &graph, int at, int from)
	{
		if (graph[at].empty())
			return {1, 1};
		pair<int, int> res = {-1, -1};
		for (auto to : graph[at])
		{
			if (to == from)
				continue;
			auto tmp = postorder(graph, to, at);
			if (res.first == -1)
				res = tmp;
			else
			{
				res.second = ((combination(res.first + tmp.first, res.first) % MOD) * res.second % MOD) * tmp.second % MOD;
				res.first += tmp.first;
			}
		}
		++res.first;
		return res;
	}

	long combination(long n, long m)
	{
		int res = 1;
		for (int i = 1; i <= m; ++i)
			res = res * (n - m + i) / i;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};