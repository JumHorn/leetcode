#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
	{
		sort(tiles.begin(), tiles.end());
		int N = tiles.size(), res = min(carpetLen, tiles[0][1] - tiles[0][0] + 1), sum = tiles[0][1] - tiles[0][0] + 1, start = tiles[0][0] - 1;
		for (int i = 1, j = 0; i < N; ++i)
		{
			sum += tiles[i][1] - tiles[i][0] + 1;
			start = tiles[i][1] - carpetLen;
			for (; j < N && tiles[j][1] <= start; ++j)
				sum -= tiles[j][1] - tiles[j][0] + 1;
			int delta = 0;
			if (j < N)
				delta = max(start - tiles[j][0] + 1, 0);
			res = max(res, sum - delta);
		}
		return res;
	}
};