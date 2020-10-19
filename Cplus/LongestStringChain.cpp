#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestStrChain(vector<string> &words)
	{
		int N = words.size();
		sort(words.begin(), words.end(), *this);
		vector<int> dp(N);
		int res = 1;
		for (int i = 0; i < N; ++i)
		{
			dp[i] = 1;
			for (int j = i - 1; j >= 0; --j)
			{
				if (words[i].length() - words[j].length() > 1)
					break;
				if (words[i].length() == words[j].length())
					continue;
				if (checkValid(words[j], words[i]))
				{
					dp[i] = max(dp[i], dp[j] + 1);
					res = max(res, dp[i]);
				}
			}
		}
		return res;
	}

	bool checkValid(string &lhs, string &rhs) //lhs is subsequence of rhs or not
	{
		int M = lhs.length(), N = rhs.length(), i = 0;
		for (int j = 0; i < M && j < N; ++j)
		{
			if (lhs[i] == rhs[j])
				++i;
		}
		return i == M;
	}

	bool operator()(const string &lhs, const string &rhs)
	{
		return lhs.length() < rhs.length();
	}
};