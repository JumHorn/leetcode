#include <vector>
using namespace std;

class Solution
{
public:
	int oddCells(int n, int m, vector<vector<int>> &indices)
	{
		vector<int> row(n), col(m);
		for (int k = 0; k < indices.size(); ++k)
		{
			++row[indices[k][0]];
			++col[indices[k][1]];
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if ((row[i] + col[j]) % 2 == 1)
					++res;
			}
		}
		return res;
	}
};