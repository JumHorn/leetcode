#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestCycle(vector<int> &edges)
	{
		int N = edges.size();
		vector<int> indgree(N);
		for (int u = 0; u < N; ++u)
		{
			int v = edges[u];
			if (v != -1)
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
			if (edges[v] == -1)
				continue;
			if (--indgree[edges[v]] == 0)
				q.push(edges[v]);
		}

		vector<bool> seen(N);
		int max_ring_size = -1;
		for (int i = 0; i < N; ++i)
		{
			if (indgree[i] == 0 || seen[i])
				continue;
			int ringsize = findRing(edges, i, seen);
			if (ringsize >= 2)
				max_ring_size = max(max_ring_size, ringsize);
		}
		return max_ring_size;
	}

	//get ring
	int findRing(vector<int> &edges, int at, vector<bool> &seen)
	{
		int res = 0;
		for (; at != -1 && !seen[at]; at = edges[at])
		{
			seen[at] = true;
			++res;
		}
		return res;
	}
};