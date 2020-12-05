#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		for (int i = 0; i < (int)board.size(); ++i)
		{
			for (int j = 0; j < (int)board[0].size(); ++j)
			{
				if (backTracking(board, i, j, word, 0))
					return true;
			}
		}
		return false;
	}

	bool backTracking(vector<vector<char>> &board, int row, int col, const string &word, int index)
	{
		int M = board.size(), N = board[0].size();
		if (index >= (int)word.length())
			return true;
		if (row < 0 || row >= M || col < 0 || col >= N)
			return false;
		if (word[index] != board[row][col])
			return false;
		board[row][col] = ~board[row][col]; //make it negative as seen
		//board backTracking direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int k = 0; k < 4; ++k)
		{
			int dx = row + path[k], dy = col + path[k + 1];
			if (backTracking(board, dx, dy, word, index + 1))
				return true;
		}
		board[row][col] = ~board[row][col];
		return false;
	}
};