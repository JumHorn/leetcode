#include <vector>
using namespace std;

class Solution
{
public:
	int oddCells(int n, int m, vector<vector<int>> &indices)
	{
		vector<int> row(n), col(m);
		for (auto &index : indices)
		{
			++row[index[0]];
			++col[index[1]];
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