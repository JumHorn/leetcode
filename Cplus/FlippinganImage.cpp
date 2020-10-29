#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
	{
		int M = A.size(), N = A[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j * 2 < N; ++j)
			{
				if (A[i][j] == A[i][N - j - 1])
				{
					A[i][j] ^= 1;
					A[i][N - j - 1] = A[i][j];
				}
			}
		}
		return A;
	}
};