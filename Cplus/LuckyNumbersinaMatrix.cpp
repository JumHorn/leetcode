#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix)
	{
		int m = matrix.size(), n = matrix[0].size();
		vector<int> row(m), col(n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (matrix[i][j] < matrix[i][row[i]])
					row[i] = j;
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 1; i < m; i++)
			{
				if (matrix[i][j] > matrix[col[j]][j])
					col[j] = i;
			}
		}
		vector<int> res;
		for (int i = 0; i < m; i++)
			if (col[row[i]] == i)
				res.push_back(matrix[i][row[i]]);
		return res;
	}
};
