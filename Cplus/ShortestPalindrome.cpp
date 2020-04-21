#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//kmp next array

class Solution
{
public:
	string shortestPalindrome(string s)
	{
		string dump = s;
		reverse(dump.begin(), dump.end());
		string pattern = s + "#" + dump;
		int n = pattern.length();
		vector<int> next(n);
		for (int i = 1, j = 0; i < n; i++)
		{
			while (j > 0 && pattern[i] != pattern[j])
				j = next[j - 1];
			if (pattern[i] == pattern[j])
				++j;
			next[i] = j;
		}
		return dump.substr(0, n / 2 - next[n - 1]) + s;
	}
};