#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getBiggestThree(vector<vector<int>> &grid)
	{
		set<int> s;
		int M = grid.size(), N = grid[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int sz = 0; i + sz < M && i - sz >= 0 && j + 2 * sz < N; ++sz)
				{
					int x = i, y = j, r_sum = 0;
					do
						r_sum += grid[x++][y++];
					while (x < i + sz);
					if (sz > 0)
					{
						do
							r_sum += grid[x--][y++];
						while (y < j + 2 * sz);
						do
							r_sum += grid[x--][y--];
						while (x > i - sz);
						do
							r_sum += grid[x++][y--];
						while (x < i);
					}
					s.insert(r_sum);
					if (s.size() > 3)
						s.erase(begin(s));
				}
			}
		}
		return vector<int>(rbegin(s), rend(s));
	}
};