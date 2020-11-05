#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
	{
		int M = rowSum.size(), N = colSum.size();
		vector<vector<int>> res(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				res[i][j] = min(rowSum[i], colSum[j]);
				rowSum[i] -= res[i][j];
				colSum[j] -= res[i][j];
			}
		}
		return res;
	}
};