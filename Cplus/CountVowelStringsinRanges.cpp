#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
	{
		int N = words.size();
		vector<int> prefix(1);
		for (auto &str : words)
		{
			if (vowel(str[0]) && vowel(str.back()))
				prefix.push_back(prefix.back() + 1);
			else
				prefix.push_back(prefix.back() + 0);
		}

		vector<int> res;
		for (auto &q : queries)
		{
			int l = q[0], r = q[1];
			res.push_back(prefix[r + 1] - prefix[l]);
		}
		return res;
	}

	bool vowel(char c)
	{
		string vow = "aeiou";
		for (auto v : vow)
		{
			if (c == v)
				return true;
		}
		return false;
	}
};