#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPrintable(vector<vector<int>> &targetGrid)
	{
		int M = targetGrid.size(), N = targetGrid[0].size();
		vector<vector<int>> rect(61, {M, N, 0, 0});
		unordered_set<int> color;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int c = targetGrid[i][j];
				color.insert(c);
				rect[c][0] = min(rect[c][0], i);
				rect[c][1] = min(rect[c][1], j);
				rect[c][2] = max(rect[c][2], i);
				rect[c][3] = max(rect[c][3], j);
			}
		}
		while (!color.empty())
		{
			unordered_set<int> next_color;
			for (auto c : color)
			{
				if (!checkAndColor(targetGrid, rect[c][0], rect[c][1], rect[c][2], rect[c][3], c))
					next_color.insert(c);
			}
			if (next_color.size() == color.size())
				return false;
			color.swap(next_color);
		}
		return true;
	}

	//if true then clear the color
	bool checkAndColor(vector<vector<int>> &grid, int left, int bottom, int right, int top, int color)
	{
		for (int i = left; i <= right; ++i)
		{
			for (int j = bottom; j <= top; ++j)
			{
				if (grid[i][j] != -1 && grid[i][j] != color)
					return false;
			}
		}
		for (int i = left; i <= right; ++i)
		{
			for (int j = bottom; j <= top; ++j)
			{
				if (grid[i][j] == color)
					grid[i][j] = -1;
			}
		}
		return true;
	}
};