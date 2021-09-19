#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findPeakGrid(vector<vector<int>> &mat)
	{
		int M = mat.size(), N = mat[0].size();
		int lo = 0, hi = M - 1;
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int max_col = 0;
			// find max col in mat[mi]
			for (int j = 0; j < N; ++j)
			{
				if (mat[mi][j] > mat[mi][max_col])
					max_col = j;
			}
			if ((mi == 0 || mat[mi][max_col] > mat[mi - 1][max_col]) &&
				(mi == M - 1 || mat[mi][max_col] > mat[mi + 1][max_col]))
				return {mi, max_col};
			// one of the condition in the above if clause
			if (mi == 0 || mat[mi][max_col] > mat[mi - 1][max_col])
				lo = mi + 1;
			else
				hi = mi - 1;
		}
		return {-1, -1};
	}
};