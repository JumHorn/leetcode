#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//kmp next array

class Solution
{
public:
	string shortestPalindrome(string s)
	{
		string dup = s;
		reverse(dup.begin(), dup.end());
		string pattern = s + "#" + dup;
		int N = pattern.length();
		vector<int> next(N);
		for (int i = 1, j = 0; i < N; ++i)
		{
			while (j > 0 && pattern[i] != pattern[j])
				j = next[j - 1];
			if (pattern[i] == pattern[j])
				++j;
			next[i] = j;
		}
		return dup.substr(0, N / 2 - next[N - 1]) + s;
	}
};