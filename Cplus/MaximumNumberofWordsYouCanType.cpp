#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int canBeTypedWords(string text, string brokenLetters)
	{
		vector<int> v(26);
		for (auto c : brokenLetters)
			v[c - 'a'] = 1;
		int res = 0;
		stringstream ss(text);
		string word;
		while (ss >> word)
		{
			if (check(word, v))
				++res;
		}
		return res;
	}

	bool check(string &word, vector<int> &v)
	{
		for (auto c : word)
		{
			if (v[c - 'a'] == 1)
				return false;
		}
		return true;
	}
};