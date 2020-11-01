#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> luckyNumbers(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		vector<int> row(M), col(N);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				if (matrix[i][j] < matrix[i][row[i]])
					row[i] = j;
			}
		}
		for (int j = 0; j < N; ++j)
		{
			for (int i = 1; i < M; ++i)
			{
				if (matrix[i][j] > matrix[col[j]][j])
					col[j] = i;
			}
		}
		vector<int> res;
		for (int i = 0; i < M; ++i)
		{
			if (col[row[i]] == i)
				res.push_back(matrix[i][row[i]]);
		}
		return res;
	}
};