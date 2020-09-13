#include <vector>
using namespace std;

class Solution
{
public:
	int numSpecial(vector<vector<int>>& mat)
	{
		int res = 0, M = mat.size(), N = mat[0].size();
		for (int i = 0; i < M; ++i)
		{
			int index = -1, j = 0;
			for (j = 0; j < N; ++j)
			{
				if (mat[i][j] == 1)
				{
					if (index != -1)
						break;
					index = j;
				}
			}
			if (j == N && index != -1)
			{
				int count = 0;
				for (int i = 0; i < M; ++i)
					count += mat[i][index];
				if (count == 1)
					++res;
			}
		}
		return res;
	}
};
