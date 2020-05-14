#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
	{
		vector<unordered_map<int, int>> graph(n);
		for (auto& edge : edges)
		{
			graph[edge[0]][edge[1]] = 1;
			graph[edge[1]][edge[0]] = 1;
		}
		int res = postorder(graph, 0, hasApple);
		return res >= 0 ? res : 0;
	}

	int postorder(vector<unordered_map<int, int>>& graph, int index, vector<bool>& hasApple)
	{
		int res = 0;
		for (auto& node : graph[index])
		{
			if (node.second == 1)
			{
				graph[node.first][index] = 0;
				int tmp = postorder(graph, node.first, hasApple);
				if (tmp >= 0)
					res += tmp + 2;
			}
		}
		if (!hasApple[index] && res == 0)
			return -1;
		return res;
	}
};
