#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0)
	{
		vector<vector<int>> res = {{r0, c0}};
		vector<vector<int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int i = r0, j = c0;
		for (int n = 0; (int)res.size() < R * C; ++n)
		{
			for (int k = 0; k < n / 2 + 1; ++k)
			{
				i += path[n % 4][0], j += path[n % 4][1];
				if (0 <= i && i < R && 0 <= j && j < C)
					res.push_back({i, j});
			}
		}
		return res;
	}
};