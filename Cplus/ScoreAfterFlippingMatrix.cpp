#include <vector>
using namespace std;

class Solution
{
public:
	int matrixScore(vector<vector<int>> &A)
	{
		int M = A.size(), N = A[0].size(), res = 0;
		for (int j = 0; j < N; ++j)
		{
			int one = 0;
			for (int i = 0; i < M; ++i)
				one += A[i][j] ^ A[i][0];
			res += max(one, M - one) * (1 << (N - j - 1));
		}
		return res;
	}
};