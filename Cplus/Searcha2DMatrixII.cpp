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
		int N = matrix.size();
		for (int i = 0, j = (int)matrix[0].size() - 1; i < N && j >= 0;)
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