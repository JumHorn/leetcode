#include <vector>
using namespace std;

class Solution
{
public:
	int closestMeetingNode(vector<int> &edges, int node1, int node2)
	{
		int N = edges.size(), res = -1;
		vector<int> dist1(N, -1), dist2(N, -1);
		minDist(edges, node1, dist1);
		minDist(edges, node2, dist2);
		for (int i = 0; i < N; ++i)
		{
			if ((dist1[i] >= 0 && dist2[i] >= 0) && (res == -1 || max(dist1[res], dist2[res]) > max(dist1[i], dist2[i])))
				res = i;
		}
		return res;
	}

	void minDist(vector<int> &edges, int at, vector<int> &dist)
	{
		for (int d = 0; at != -1 && dist[at] == -1; at = edges[at])
			dist[at] = d++;
	}
};