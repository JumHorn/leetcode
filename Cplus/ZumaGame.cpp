#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int findMinStep(string board, string hand)
	{
		unordered_map<char, int> handmap;
		for (auto c : hand)
			++handmap[c];
		int res = dfs(board, handmap);
		return res >= 100 ? -1 : res;
	}

	int dfs(string board, unordered_map<char, int> &hand)
	{
		if (board.empty())
			return 0;
		int res = 100, N = board.length();
		for (int i = 0, j = 0; i < N; i = j++)
		{
			while (j < N && board[i] == board[j])
				++j;
			int insert = max(3 - (j - i), 0);
			if (hand[board[i]] >= insert)
			{
				hand[board[i]] -= insert;
				res = min(res, dfs(board.substr(0, i) + board.substr(j), hand) + insert);
				hand[board[i]] += insert;
			}
		}
		return res;
	}
};