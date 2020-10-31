#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
	{
		vector<int> res(n);
		vector<vector<int>> graph(n);
		for (auto &path : paths)
		{
			graph[path[0] - 1].push_back(path[1] - 1);
			graph[path[1] - 1].push_back(path[0] - 1);
		}
		for (int i = 0; i < n; ++i)
		{
			if (res[i] == 0)
				plant(graph, i, res);
		}
		return res;
	}

	int flower(int n)
	{
		int res = 0;
		while ((1 << res) & n)
			++res;
		return res + 1;
	}

	void plant(vector<vector<int>> &graph, int index, vector<int> &garden)
	{
		int color = 0;
		for (auto c : graph[index])
		{
			if (garden[c] != 0)
				color |= 1 << (garden[c] - 1);
		}
		garden[index] = flower(color);
	}
};