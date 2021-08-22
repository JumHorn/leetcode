#include <vector>
using namespace std;

// only less than one negative number in final result

class Solution
{
public:
	long long maxMatrixSum(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size(), negativeCount = 0, absminval = INT_MAX;
		long long res = 0;
		for (auto &row : matrix)
		{
			for (auto n : row)
			{
				res += abs(n);
				absminval = min(absminval, abs(n));
				if (n < 0)
					++negativeCount;
			}
		}
		if (negativeCount % 2 == 0)
			return res;
		return res - 2 * absminval;
	}
};