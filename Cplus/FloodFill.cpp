#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
	{
		if (image[sr][sc] != newColor)
			dfs(image, sr, sc, image[sr][sc], newColor);
		return image;
	}

	void dfs(vector<vector<int>> &image, int row, int col, int oldColor, int newColor)
	{
		int M = image.size(), N = image[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || image[row][col] != oldColor)
			return;
		image[row][col] = newColor;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			dfs(image, row + path[i], col + path[i + 1], oldColor, newColor);
	}
};