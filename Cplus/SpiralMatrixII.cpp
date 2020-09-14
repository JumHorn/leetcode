#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> res(n, vector<int>(n));
		vector<int> range = {0, n, 0, n}; //left,right,bottom,top
		int i = 0, j = 0, d = 0;
		vector<vector<int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		vector<vector<int>> rangechange = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, -1, 0, 0}, {0, 0, 0, -1}};
		for (int k = 0; k < n * n; ++k)
		{
			res[i][j] = k + 1;
			int dx = i + path[d][0], dy = j + path[d][1];
			if (dx >= range[2] && dx < range[3] && dy >= range[0] && dy < range[1])
			{
				i = dx;
				j = dy;
			}
			else
			{
				d = (d + 1) % 4;
				i += path[d][0];
				j += path[d][1];
				for (int i = 0; i < 4; ++i)
					range[i] += rangechange[d][i];
			}
		}
		return res;
	}
};