#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> palindromePairs(vector<string> &words)
	{
		unordered_map<string, int> m; //{str,index}
		int N = words.size();
		for (int i = 0; i < N; ++i)
			m[words[i]] = i;
		vector<vector<int>> res;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= (int)words[i].length(); ++j)
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
		for (int i = 0, j = word.length() - 1; i < j; ++i, --j)
		{
			if (word[i] != word[j])
				return false;
		}
		return true;
	}
};