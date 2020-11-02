#include <vector>
using namespace std;

class Solution
{
public:
	int numSpecial(vector<vector<int>> &mat)
	{
		int res = 0, M = mat.size(), N = mat[0].size();
		vector<int> row(M), col(N);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (mat[i][j] == 1)
				{
					++row[i];
					++col[j];
				}
			}
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
					++res;
			}
		}
		return res;
	}
};