#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSideLength(vector<vector<int>> &mat, int threshold)
	{
		int m = mat.size(), n = mat[0].size();
		int res = 0;
		vector<vector<int>> v(m + 1, vector<int>(n + 1));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				v[i][j] += mat[i - 1][j - 1] - v[i - 1][j - 1] + v[i][j - 1] + v[i - 1][j];
				if (mat[i - 1][j - 1] <= threshold)
					res = 1;
			}
		if (res == 0)
			return res;
		res = min(m, n);
		if (threshold >= v[res][res])
			return res;
		int lo = 1, hi = min(m, n), mi;
		while (lo < hi)
		{
			mi = (hi - lo) / 2 + lo;
			if (checkSum(v, mi, threshold))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool checkSum(vector<vector<int>> &v, int size, int threshold)
	{
		int m = v.size(), n = v[0].size();
		for (int i = 0; i < m - size; i++)
			for (int j = 0; j < n - size; j++)
				if (v[i + size][j + size] - v[i][j + size] - v[i + size][j] + v[i][j] <= threshold)
					return true;
		return false;
	}
};