#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumInvitations(vector<int> &favorite)
	{
		int N = favorite.size();
		vector<vector<int>> graph(N); //inverse favorite
		vector<int> indgree(N);
		for (int u = 0; u < N; ++u)
		{
			int v = favorite[u];
			graph[v].push_back(u);
			++indgree[v];
		}

		//拓扑排序减去入度为0节点并保留基环
		queue<int> q;
		for (int i = 0; i < N; ++i)
		{
			if (indgree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			if (--indgree[favorite[v]] == 0)
				q.push(favorite[v]);
		}

		vector<bool> seen(N);
		int max_ring_size = 0, sum_chain_size = 0;
		for (int i = 0; i < N; ++i)
		{
			if (indgree[i] == 0 || seen[i])
				continue;
			vector<int> ring;
			findRing(favorite, i, seen, ring);
			int ringsize = ring.size();
			if (ringsize > 2)
				max_ring_size = max(max_ring_size, ringsize);
			else
			{
				int u = ring[0], v = ring[1];
				sum_chain_size += maxDepth(graph, u, v);
				sum_chain_size += maxDepth(graph, v, u);
			}
		}
		return max(max_ring_size, sum_chain_size);
	}

	//get ring
	void findRing(vector<int> &favorite, int at, vector<bool> &seen, vector<int> &ring)
	{
		for (; !seen[at]; at = favorite[at])
		{
			ring.push_back(at);
			seen[at] = true;
		}
	}

	int maxDepth(vector<vector<int>> &graph, int from, int at)
	{
		int res = 0;
		for (auto to : graph[at])
		{
			if (to != from)
				res = max(res, maxDepth(graph, at, to));
		}
		return res + 1;
	}
};