#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string shortestCompletingWord(string licensePlate, vector<string> &words)
	{
		string res;
		vector<int> hash = countAlpha(licensePlate);
		for (auto &word : words)
		{
			if (contains(hash, countAlpha(word)) && (res.empty() || res.length() > word.length()))
				res = word;
		}
		return res;
	}

	bool contains(const vector<int> &lhs, const vector<int> &rhs) //rhs constain lhs
	{
		for (int i = 0; i < (int)lhs.size(); ++i)
		{
			if (lhs[i] > rhs[i])
				return false;
		}
		return true;
	}

	vector<int> countAlpha(const string &word)
	{
		vector<int> res(26);
		for (auto c : word)
		{
			if (isalpha(c))
				++res[tolower(c) - 'a'];
		}
		return res;
	}
};