#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int catMouseGame(vector<vector<int>> &graph)
	{
		int N = graph.size();
		//status[node] : who wins in the end if we start from this node
		int status[50][50][3] = {0}; // status[mouse_location][cat_location][turn]
		//children_num[node] : the number of neutral children of this node
		int children_num[50][50][3] = {0}; // children_num[mouse_location][cat_location][turn]

		for (int m = 0; m < N; ++m) //mouse location
		{
			for (int c = 0; c < N; ++c) //cat location
			{
				children_num[m][c][MOUSE_TURN] = graph[m].size();
				children_num[m][c][CAT_TURN] = graph[c].size();
				for (int x : graph[c])
				{
					if (x == 0) //The cat can not stay at the hole (position 0).
					{
						children_num[m][c][CAT_TURN]--;
						break;
					}
				}
			}
		}

		// enqueued : all nodes that we know who wins in the end. Nodes with DRAW status is not in this queue.
		queue<vector<int>> q;
		for (int i = 0; i < N; ++i)
		{
			for (int t = 1; t <= 2; ++t) //turn
			{
				status[0][i][t] = MOUSE_WIN; //The mouse wins if it is at the hole (position 0).
				q.push({0, i, t, MOUSE_WIN});
				if (i > 0)
				{
					status[i][i][t] = CAT_WIN; //The cat wins if mouse and cat are at the same location.
					q.push({i, i, t, CAT_WIN});
				}
			}
		}

		// percolate nodes that we know who wins in the end
		while (!q.empty())
		{
			int m = q.front()[0], c = q.front()[1], t = q.front()[2], s = q.front()[3]; //mouse_location, cat_location, turn, status
			q.pop();
			for (auto &parent : parents(graph, m, c, t)) // for every parent of this node (m, c, t) :
			{
				int m2 = parent[0], c2 = parent[1], t2 = parent[2]; //mouse_location2, cat_location2, turn2
				if (status[m2][c2][t2] == DRAW)						// if we do not know who wins in this parent node
				{
					if (t2 == MOUSE_TURN && s == MOUSE_WIN || t2 == CAT_TURN && s == CAT_WIN)
					{
						// if the parent can make a winning move (mouse to MOUSE_WIN, or cat to CAT_WIN)
						status[m2][c2][t2] = s;
						q.push({m2, c2, t2, s});
					}
					else
					{
						// else, this parent has neutral children_num[parent]--.
						// Enqueue if all children of this parent are colored as losing moves.
						if (--children_num[m2][c2][t2] == 0)
						{
							status[m2][c2][t2] = t2 == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
							q.push({m2, c2, t2, status[m2][c2][t2]});
						}
					}
				}
			}
		}

		return status[1][2][MOUSE_TURN]; //The mouse is at location 1. The cat is at location 2. The mouse moves first.
	}

	// What nodes could play their turn to arrive at node (m, c, t) ?
	vector<vector<int>> parents(vector<vector<int>> &graph, int m, int c, int t)
	{
		vector<vector<int>> res;
		if (t == CAT_TURN)
		{
			for (int m2 : graph[m])
				res.push_back({m2, c, MOUSE_TURN});
		}
		else
		{
			for (int c2 : graph[c])
			{
				if (c2 > 0) //The cat can not stay at the hole (position 0).
					res.push_back({m, c2, CAT_TURN});
			}
		}
		return res;
	}

private:
	const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2, MOUSE_TURN = 1, CAT_TURN = 2;
};