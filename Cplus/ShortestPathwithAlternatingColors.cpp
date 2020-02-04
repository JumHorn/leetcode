#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		for (int i = 0; i < (int)red_edges.size(); i++)
			graph[red_edges[i][0]][red_edges[i][1]] |= 1;
		for (int i = 0; i < (int)blue_edges.size(); i++)
			graph[blue_edges[i][0]][blue_edges[i][1]] |= 2;
		vector<int> res(n, -1);
		vector<int> visited(n);
		queue<pair<int, int>> q;
		int len = 0;
		q.push({0, 1});
		q.push({0, 2});
		res[0] = 0;
		visited[0] = 3;
		while (!q.empty())
		{
			int size = q.size();
			++len;
			while (--size >= 0)
			{
				auto tmp = q.front();
				q.pop();
				for (int i = 0; i < n; i++)
				{
					if ((graph[tmp.first][i] & (3 - tmp.second)) != 0)
					{
						if ((visited[i] & (3 - tmp.second)) != 0)
							continue;
						visited[i] |= 3 - tmp.second;

						if (res[i] == -1)
							res[i] = len;
						else
							res[i] = min(res[i], len);
						q.push({i, 3 - tmp.second});
					}
				}
			}
		}
		return res;
	}
};
