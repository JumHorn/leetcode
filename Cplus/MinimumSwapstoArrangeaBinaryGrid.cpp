#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSwaps(vector<vector<int>> &grid)
	{
		int N = grid.size();
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
		{
			int j = N - 1;
			while (j >= 0 && grid[i][j] == 0)
				--j;
			v[i] = N - 1 - j;
		}

		int res = 0;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (v[i] >= N - 1 - i)
				continue;
			for (j = i + 1; j < N && v[j] < N - 1 - i;)
				++j;
			if (j == N)
				return -1;
			res += j - i;
			for (; j > i; --j)
				swap(v[j], v[j - 1]);
		}
		return res;
	}
};