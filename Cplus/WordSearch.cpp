#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		for (int i = 0; i < (int)board.size(); i++)
		{
			for (int j = 0; j < (int)board[0].size(); j++)
				if (dfs(board, word, 0, i, j))
					return true;
		}
		return false;
	}

	bool dfs(vector<vector<char>> &board, const string &word, int index, int i, int j)
	{
		if (board[i][j] != word[index])
			return false;
		++index;
		if (index >= (int)word.length())
			return true;
		char c = board[i][j];
		board[i][j] = '\0';
		if (i + 1 < (int)board.size() && dfs(board, word, index, i + 1, j))
			return true;
		if (i - 1 >= 0 && dfs(board, word, index, i - 1, j))
			return true;
		if (j + 1 < (int)board[0].size() && dfs(board, word, index, i, j + 1))
			return true;
		if (j - 1 >= 0 && dfs(board, word, index, i, j - 1))
			return true;
		board[i][j] = c;
		return false;
	}
};