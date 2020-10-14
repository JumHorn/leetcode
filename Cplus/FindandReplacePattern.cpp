#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findAndReplacePattern(vector<string> &words, string pattern)
	{
		vector<string> res;
		string p = normaliseWord(pattern);
		for (auto &word : words)
		{
			string w = normaliseWord(word);
			if (w == p)
				res.push_back(word);
		}
		return res;
	}

	string normaliseWord(const string &word) //encode the first appeared element
	{
		unordered_map<char, int> m;
		string res;
		for (auto c : word)
		{
			if (m.find(c) == m.end())
				m[c] = m.size();
			res.push_back('a' + m[c]);
		}
		return res;
	}
};