#include <cmath>
#include <vector>
using namespace std;

/*
counting sort
*/

class Solution
{
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
	{
		vector<int> count(R + C);
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				int dist = abs(r - r0) + abs(c - c0);
				++count[dist];
			}
		}
		for (int i = 1; i < (int)count.size(); ++i)
			count[i] += count[i - 1];

		vector<vector<int>> res(R * C);
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				int dist = abs(r - r0) + abs(c - c0);
				res[--count[dist]] = {r, c};
			}
		}
		return res;
	}
};