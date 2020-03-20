#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

/*
step 1. find the cell with minimum height and the connected same height cell using priority queue
step 2. find the minimum height around these cell(maximum water trap)
step 3. add these water to result and fill these cell to the mimimum height in step 2
step 4. go on to 1 until no cell left in the queue
*/

class Solution
{
public:
	int trapRainWater(vector<vector<int>> &heightMap)
	{
		int res = 0, m = heightMap.size(), n = heightMap[0].size();
		if (m < 3 || n < 3)
			return 0;
		priority_queue<pair<int, int>> q; //height,position queue
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				q.push({-heightMap[i][j], i * n + j});
		while (!q.empty())
		{
			unordered_set<int> visited;
			pair<int, int> top = q.top();
			q.pop();
			int area = 0, height = -top.first, i = top.second / n, j = top.second % n;
			if (heightMap[i][j] == -1 || heightMap[i][j] != height)
				continue;
			pair<int, int> tmp = dfs(heightMap, visited, i, j, height);
			if (tmp.first >= 0)
			{
				for (auto number : visited)
				{
					heightMap[number / n][number % n] = tmp.second;
					q.push({-tmp.second, number});
				}
				area += tmp.first;
				res += (tmp.second - height) * area;
			}
			else
			{
				//fill all the hole
				fillHoles(heightMap, i, j, height);
			}
		}
		return res;
	}

	void fillHoles(vector<vector<int>> &heightMap, int i, int j, int h)
	{
		int m = heightMap.size(), n = heightMap[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n)
			return;
		if (heightMap[i][j] != h)
			return;
		heightMap[i][j] = -1;
		int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int k = 0; k < 4; k++)
		{
			int x = i + direction[k][0], y = j + direction[k][1];
			fillHoles(heightMap, x, y, h);
		}
	}

	//dfs to find the number of the same height
	//return the number of the same height and minimum higher cell height
	pair<int, int> dfs(vector<vector<int>> &heightMap, unordered_set<int> &visited, int i, int j, int h)
	{
		int m = heightMap.size(), n = heightMap[0].size();
		if (heightMap[i][j] == -1)
			return {-1, INT_MAX};
		if (visited.find(i * n + j) != visited.end())
			return {0, INT_MAX};
		if (heightMap[i][j] > h)
			return {0, heightMap[i][j]};
		if (i <= 0 || i >= m - 1 || j <= 0 || j >= n - 1)
			return {-1, INT_MAX};
		visited.insert(i * n + j);
		int numer = 1, height = INT_MAX;
		int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int k = 0; k < 4; k++)
		{
			int x = i + direction[k][0], y = j + direction[k][1];
			pair<int, int> tmp = dfs(heightMap, visited, x, y, h);
			if (tmp.first < 0)
				return {-1, INT_MAX};
			numer += tmp.first;
			height = min(height, tmp.second);
		}
		return {numer, height};
	}
};