#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findBall(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<int> res(N); //index
		for (int i = 0; i < N; ++i)
			res[i] = i;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (res[j] == -1)
					continue;
				int index = res[j];
				if (grid[i][index] == -1)
				{
					if (index == 0 || grid[i][index - 1] == 1)
						res[j] = -1;
					else
						res[j] = index - 1;
				}
				else
				{
					if (index == N - 1 || grid[i][index + 1] == -1)
						res[j] = -1;
					else
						res[j] = index + 1;
				}
			}
		}
		return res;
	}
};