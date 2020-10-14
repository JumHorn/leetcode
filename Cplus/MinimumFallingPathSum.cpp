#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFallingPathSum(vector<vector<int>> &A)
	{
		int M = A.size(), N = A[0].size();
		for (int i = 1; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				A[i][j] += min({A[i - 1][max(0, j - 1)], A[i - 1][j], A[i - 1][min(j + 1, N - 1)]});
		}
		return *min_element(A.back().begin(), A.back().end());
	}
};