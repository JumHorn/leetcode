#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> imageSmoother(vector<vector<int>> &M)
	{
		int m = M.size(), n = M[0].size();
		vector<vector<int>> res(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int gray = 0, count = 0;
				for (int k = max(0, i - 1); k <= min(m - 1, i + 1); ++k)
				{
					for (int l = max(0, j - 1); l <= min(n - 1, j + 1); ++l)
					{
						++count;
						gray += M[k][l];
					}
				}
				res[i][j] = gray / count;
			}
		}
		return res;
	}
};