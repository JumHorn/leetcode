#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		for (auto &red : red_edges)
			graph[red[0]][red[1]] |= 0b01;
		for (auto &blue : blue_edges)
			graph[blue[0]][blue[1]] |= 0b10;
		vector<int> res(n, -1), seen(n);
		queue<pair<int, int>> q; //{node,color}
		int dist = 0;
		q.push({0, 0b01});
		q.push({0, 0b10});
		res[0] = 0;
		seen[0] = 0b11;
		while (!q.empty())
		{
			++dist;
			int size = q.size();
			while (--size >= 0)
			{
				int node = q.front().first, color = q.front().second;
				q.pop();
				for (int i = 0; i < n; ++i)
				{
					if ((graph[node][i] & (0b11 ^ color)) != 0)
					{
						if ((seen[i] & (0b11 ^ color)) == 0)
						{
							seen[i] |= 0b11 ^ color;
							if (res[i] == -1)
								res[i] = dist;
							else
								res[i] = min(res[i], dist);
							q.push({i, 0b11 ^ color});
						}
					}
				}
			}
		}
		return res;
	}
};