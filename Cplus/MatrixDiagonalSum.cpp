#include <vector>
using namespace std;

class Solution
{
public:
	int diagonalSum(vector<vector<int>>& mat)
	{
		int n = mat.size(), res = 0;
		for (int i = 0; i < n; ++i)
			res += mat[i][i] + mat[n - i - 1][i];
		if (n % 2 == 1)
			res -= mat[n / 2][n / 2];
		return res;
	}
};
