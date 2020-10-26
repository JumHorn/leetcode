#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findWords(vector<string> &words)
	{
		vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"}, res;
		unordered_map<char, int> m; //{char,row}
		for (int i = 0; i < (int)rows.size(); ++i)
		{
			for (auto &c : rows[i])
				m[c] = i;
		}
		for (auto &word : words)
		{
			if (all_of(word.begin(), word.end(), [&](char c) { return m[::toupper(c)] == 0; }) ||
				all_of(word.begin(), word.end(), [&](char c) { return m[::toupper(c)] == 1; }) ||
				all_of(word.begin(), word.end(), [&](char c) { return m[::toupper(c)] == 2; }))
				res.push_back(word);
		}
		return res;
	}
};