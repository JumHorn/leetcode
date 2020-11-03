#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string arrangeWords(string text)
	{
		vector<pair<string, int>> word = split(text);
		word[0].first[0] = tolower(word[0].first[0]);
		sort(word.begin(), word.end(), *this);
		string res;
		res += word[0].first;
		for (int i = 1; i < (int)word.size(); ++i)
			res += " " + word[i].first;
		res[0] = toupper(res[0]);
		return res;
	}

	vector<pair<string, int>> split(string &text)
	{
		int i = 0, j = 0, n = text.length(), index = 0;
		vector<pair<string, int>> res;
		while (j < n)
		{
			while (j < n && text[j] != ' ')
				++j;
			res.push_back({text.substr(i, j - i), ++index});
			i = ++j;
		}
		return res;
	}

	bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs)
	{
		if (lhs.first.length() != rhs.first.length())
			return lhs.first.length() < rhs.first.length();
		return lhs.second < rhs.second;
	}
};
