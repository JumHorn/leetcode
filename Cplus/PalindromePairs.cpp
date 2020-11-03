#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> palindromePairs(vector<string> &words)
	{
		map<string, int> m;
		int n = words.size();
		for (int i = 0; i < n; ++i)
			m[words[i]] = i;
		vector<vector<int>> res;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= (int)words[i].length(); j++)
			{
				string head = words[i].substr(0, j);
				string tail = words[i].substr(j);
				if (isPalindrome(head))
				{
					reverse(tail.begin(), tail.end());
					if (m.find(tail) != m.end() && m[tail] != i)
						res.push_back({m[tail], i});
				}
				if (!tail.empty() && isPalindrome(tail))
				{
					reverse(head.begin(), head.end());
					if (m.find(head) != m.end() && m[head] != i)
						res.push_back({i, m[head]});
				}
			}
		}
		return res;
	}

	bool isPalindrome(const string &word)
	{
		int i = 0, j = word.length() - 1;
		while (i < j)
		{
			if (word[i++] != word[j--])
				return false;
		}
		return true;
	}
};