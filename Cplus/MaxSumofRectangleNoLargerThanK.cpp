#include <climits>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
	{
		int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
		for (int col = 0; col < n; col++)
		{
			vector<int> sums(m);
			for (int j = col; j < n; j++)
			{
				for (int i = 0; i < m; ++i)
					sums[i] += matrix[i][j];
				set<int> s({0});
				int currsum = 0;
				for (int i = 0; i < m; ++i)
				{
					currsum += sums[i];
					auto iter = s.lower_bound(currsum - k);
					if (iter != s.end())
						res = max(res, currsum - *iter);
					s.insert(currsum);
				}
			}
		}
		return res;
	}
};