#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool placeWordInCrossword(vector<vector<char>> &board, string word)
	{
		string reversed_word = word;
		reverse(reversed_word.begin(), reversed_word.end());
		int M = board.size(), N = board[0].size();
		for (int i = 0; i < M; ++i)
		{
			string s;
			for (int j = 0; j < N; ++j)
				s.push_back(board[i][j]);
			if (check(s, word) || check(s, reversed_word))
				return true;
		}
		for (int j = 0; j < N; ++j)
		{
			string s;
			for (int i = 0; i < M; ++i)
				s.push_back(board[i][j]);
			if (check(s, word) || check(s, reversed_word))
				return true;
		}
		return false;
	}

	bool check(string &s, string &word)
	{
		int N = s.length(), W = word.length();
		for (int i = 0, j = 0; i < N; ++i)
		{
			for (; i < N && j < W && (s[i] == word[j] || s[i] == ' '); ++i)
				++j;
			if (j == W)
			{
				if (i >= N || s[i] == '#')
					return true;
			}
			j = 0;
			while (i < N && s[i] != '#')
				++i;
		}
		return false;
	}
};