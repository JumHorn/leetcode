#include <vector>
using namespace std;

/*
search from top right
*/

class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		if (matrix.empty())
			return false;
		int m = matrix.size(), i = 0, j = matrix[0].size() - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			if (matrix[i][j] < target)
				++i;
			else
				--j;
		}
		return false;
	}
};