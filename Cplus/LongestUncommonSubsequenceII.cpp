#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLUSlength(vector<string> &strs)
	{
		vector<unordered_set<string>> v(11);
		vector<int> count(11);
		unordered_set<string> repeat;
		for (int i = 0; i < (int)strs.size(); ++i)
		{
			int len = strs[i].length();
			count[len]++;
			if (v[len].find(strs[i]) == v[len].end())
				v[len].insert(strs[i]);
			else
				repeat.insert(strs[i]);
		}

		int res = -1;
		for (int i = 10; i > 0; --i)
		{
			if (count[i] == 0)
				continue;
			for (auto &n : v[i])
			{
				if (repeat.find(n) == repeat.end())
				{
					int j;
					for (j = n.length() + 1; j <= 10; j++)
					{
						if (isAnySubsequence(n, v[j]))
							break;
					}
					if (j == 11)
						return n.length();
				}
			}
		}
		return res;
	}

	bool isAnySubsequence(const string &s, unordered_set<string> &all)
	{
		for (auto &m : all)
			if (isSubsequence(s, m))
				return true;
		return false;
	}

	bool isSubsequence(const string &lhs, const string &rhs)
	{
		unsigned int i = 0, j = 0;
		while (i < lhs.size() && j < rhs.size())
		{
			if (lhs[i] == rhs[j])
				i++;
			j++;
		}
		return i == lhs.size();
	}
};