#include <vector>
using namespace std;

class Solution
{
public:
	int findChampion(vector<vector<int>> &grid)
	{
		int N = grid.size();
		vector<int> degree(N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
					++degree[j];
			}
		}
		int res = -1, count = 0;
		for (int i = 0; i < N; ++i)
		{
			if (degree[i] == 0)
			{
				++count;
				res = i;
			}
		}
		return count == 1 ? res : -1;
	}
};