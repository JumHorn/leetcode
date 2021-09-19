#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestSubsequenceRepeatedK(string s, int k)
	{
		int N = s.length(), len = N / k;
		vector<int> count(26);
		for (auto c : s)
			++count[c - 'a'];
		for (auto &n : count)
			n /= k;
		string res;
		for (int i = len; i > 0; --i)
		{
			if (backTracking(s, count, k, i, res))
				return res;
		}
		return res;
	}

	bool backTracking(string &s, vector<int> &count, int k, int len, string &res)
	{
		if (len == 0 && repeatKTimes(s, res, k))
			return true;
		for (int i = (int)count.size() - 1; i >= 0; --i)
		{
			if (count[i] > 0)
			{
				--count[i];
				res.push_back('a' + i);
				if (backTracking(s, count, k, len - 1, res))
					return true;
				res.pop_back();
				++count[i];
			}
		}
		return false;
	}

	bool repeatKTimes(string &s, string &sub, int k)
	{
		int N = s.length(), M = sub.length();
		for (int i = 0, j = 0; k > 0 && i < N; ++i)
		{
			if (s[i] == sub[j])
			{
				++j;
				if (j == M)
				{
					--k;
					j = 0;
				}
			}
		}
		return k <= 0;
	}
};