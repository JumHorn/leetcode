#include <vector>
using namespace std;

class Solution
{
public:
	int maximumRows(vector<vector<int>> &mat, int cols)
	{
		int M = mat.size(), N = mat[0].size(), res = 0;
		for (int mask = 0; mask < (1 << N); ++mask)
		{
			if (bitCount(mask) == cols)
			{
				int count = 0;
				for (int i = 0; i < M; ++i)
				{
					int j = 0;
					for (; j < N; ++j)
					{
						if (mat[i][j] == 1 && ((mask >> j) & 1) == 0)
							break;
					}
					if (j == N)
						++count;
				}
				res = max(res, count);
			}
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};