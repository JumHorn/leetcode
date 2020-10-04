#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
	{
		int M = rowSum.size(), N = colSum.size();
		vector<vector<int>> res(M, vector<int>(N));
		long sum = 0;
		for (int i = 0; i < M; ++i)
		{
			sum += rowSum[i];
			res[i][0] = rowSum[i];
		}
		for (int j = 0; j < N; ++j)
		{
			int i = 0;
			for (i = 0; i < M; ++i)
			{
				if (colSum[j] < res[i][j])
					break;
				colSum[j] -= res[i][j];
			}
			if (colSum[j] != 0)
			{
				res[i][j + 1] = res[i][j] - colSum[j];
				res[i][j] = colSum[j];
				++i;
			}
			for (; i < M; ++i)
			{
				res[i][j + 1] = res[i][j];
				res[i][j] = 0;
			}
		}
		return res;
	}
};