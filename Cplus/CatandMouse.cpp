#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int catMouseGame(vector<vector<int>> &graph)
	{
		int N = graph.size();
		const int DRAW = 0, MOUSE = 1, CAT = 2;

		int color[50][50][3] = {0}, degree[50][50][3] = {0};

		// degree[node] : the number of neutral children of this node
		for (int m = 0; m < N; ++m)
		{
			for (int c = 0; c < N; ++c)
			{
				degree[m][c][1] = graph[m].size();
				degree[m][c][2] = graph[c].size();
				for (int x : graph[c])
				{
					if (x == 0) //The cat can not stay at the hole (position 0).
					{
						--degree[m][c][2];
						break;
					}
				}
			}
		}

		// enqueued : all nodes that are colored
		queue<vector<int>> q;
		for (int i = 0; i < N; ++i)
		{
			for (int t = 1; t <= 2; ++t)
			{
				color[0][i][t] = MOUSE; //The mouse wins if it is at the hole (position 0).
				q.push({0, i, t, MOUSE});
				if (i > 0) //The cat wins if mouse and cat are at the same location.
				{
					color[i][i][t] = CAT;
					q.push({i, i, t, CAT});
				}
			}
		}

		// percolate
		while (!q.empty())
		{
			// for nodes that are colored :
			//mouse_location, cat_location, turn, status
			int m = q.front()[0], c = q.front()[1], t = q.front()[2], s = q.front()[3];
			q.pop();
			// for every parent of this node (m, c, t) :
			for (auto &parent : parents(graph, m, c, t))
			{
				int m2 = parent[0], c2 = parent[1], t2 = parent[2];
				// if this parent is not colored :
				if (color[m2][c2][t2] == DRAW)
				{
					// if the parent can make a winning move (ie. mouse to MOUSE), do so
					if (t2 == s)
					{
						color[m2][c2][t2] = s;
						q.push({m2, c2, t2, s});
					}
					else
					{
						// else, this parent has degree[parent]--, and enqueue
						// if all children of this parent are colored as losing moves
						if (--degree[m2][c2][t2] == 0)
						{
							color[m2][c2][t2] = 3 - t2;
							q.push({m2, c2, t2, 3 - t2});
						}
					}
				}
			}
		}

		return color[1][2][1];
	}

	// What nodes could play their turn to
	// arrive at node (m, c, t) ?
	vector<vector<int>> parents(vector<vector<int>> &graph, int m, int c, int t)
	{
		vector<vector<int>> res;
		if (t == 2)
		{
			for (int m2 : graph[m])
				res.push_back({m2, c, 3 - t});
		}
		else
		{
			for (int c2 : graph[c])
			{
				if (c2 > 0)
					res.push_back({m, c2, 3 - t});
			}
		}
		return res;
	}
};