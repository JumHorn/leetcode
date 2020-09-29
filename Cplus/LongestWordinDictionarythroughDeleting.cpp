#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string findLongestWord(string s, vector<string> &d)
	{
		string res;
		sort(d.begin(), d.end(), *this);
		for (auto &str : d)
		{
			if (isSubsequence(str, s))
				return str;
		}
		return res;
	}

	bool isSubsequence(const string &lhs, const string &rhs)
	{
		unsigned int i = 0, j = 0;
		while (i < lhs.size() && j < rhs.size())
		{
			if (lhs[i] == rhs[j])
				++i;
			++j;
		}
		return i == lhs.size();
	}

	bool operator()(const string &s1, const string &s2)
	{
		if (s1.length() != s2.length())
			return s1.length() > s2.length();
		return s1 < s2;
	}
};