#include <climits>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
	{
		int M = matrix.size(), N = matrix[0].size(), res = INT_MIN;
		for (int col = 0; col < N; ++col)
		{
			vector<int> sums(M);
			for (int j = col; j < N; ++j)
			{
				for (int i = 0; i < M; ++i)
					sums[i] += matrix[i][j];
				set<int> s({0});
				int curSum = 0;
				for (int i = 0; i < M; ++i)
				{
					curSum += sums[i];
					auto iter = s.lower_bound(curSum - k);
					if (iter != s.end())
						res = max(res, curSum - *iter);
					s.insert(curSum);
				}
			}
		}
		return res;
	}
};