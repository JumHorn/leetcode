#include <vector>
using namespace std;

class Solution
{
public:
	int countNegatives(vector<vector<int>>& grid)
	{
		int res = 0, m = grid.size(), n = grid[0].size(), j = n - 1, i = m - 1;
		while (j >= 0 && grid[i][j] < 0)
			j--;
		res = n - j - 1;
		for (--i; i >= 0; i--)
		{
			if (j == n)
				break;
			if (j < 0)
				++j;
			while (j < n && grid[i][j] >= 0)
				j++;
			res += n - j;
		}
		return res;
	}
};
