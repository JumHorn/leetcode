#include <vector>
using namespace std;

class Solution
{
public:
	int numEnclaves(vector<vector<int>>& A)
	{
		int ones = 0, m = A.size(), n = A[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (A[i][j] == 1)
					ones++;
		for (int j = 0; j < n; j++)
		{
			ones -= recursive(A, 0, j);
			ones -= recursive(A, m - 1, j);
		}
		for (int i = 1; i < m - 1; i++)
		{
			ones -= recursive(A, i, 0);
			ones -= recursive(A, i, n - 1);
		}
		return ones;
	}

	int recursive(vector<vector<int>>& A, int i, int j)
	{
		if (A[i][j] == 0)
			return 0;
		A[i][j] = 0;
		int res = 1;
		if (i > 0)
			res += recursive(A, i - 1, j);
		if (i < (int)A.size() - 1)
			res += recursive(A, i + 1, j);
		if (j > 0)
			res += recursive(A, i, j - 1);
		if (j < (int)A[0].size() - 1)
			res += recursive(A, i, j + 1);
		return res;
	}
};
