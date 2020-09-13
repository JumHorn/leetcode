#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		for (int k = 0; k < 9; ++k)
		{
			int row[9] = {0};
			for (int j = 0; j < 9; ++j) //check row
			{
				if (board[k][j] != '.' && ++row[board[k][j] - '1'] > 1)
					return false;
			}
			int col[9] = {0};
			for (int i = 0; i < 9; ++i) //check col
			{
				if (board[i][k] != '.' && ++col[board[i][k] - '1'] > 1)
					return false;
			}
			int sub[9] = {0};
			for (int i = k / 3 * 3; i < k / 3 * 3 + 3; ++i)
			{
				for (int j = k % 3 * 3; j < k % 3 * 3 + 3; ++j)
				{
					if (board[i][j] != '.' && ++sub[board[i][j] - '1'] > 1)
						return false;
				}
			}
		}
		return true;
	}
};