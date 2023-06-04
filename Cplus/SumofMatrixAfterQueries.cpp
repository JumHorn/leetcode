#include <vector>
using namespace std;

class Solution
{
public:
	long long matrixSumQueries(int n, vector<vector<int>> &queries)
	{
		long long N = queries.size(), row = n, col = n, res = 0;
		vector<int> visited_row(n), visited_col(n);
		for (int i = N - 1; i >= 0; --i)
		{
			long long type = queries[i][0], index = queries[i][1], val = queries[i][2];
			if (type == 0)
			{
				if (visited_row[index] == 0)
				{
					visited_row[index] = 1;
					res += val * row;
					--col;
				}
			}
			else
			{
				if (visited_col[index] == 0)
				{
					visited_col[index] = 1;
					res += val * col;
					--row;
				}
			}
		}
		return res;
	}
};