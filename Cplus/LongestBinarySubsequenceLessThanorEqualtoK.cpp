#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubsequence(string s, int k)
	{
		int N = s.size(), ones = 0;
		long long val = 0;
		for (int i = N - 1; i >= 0 && (val | (1u << (N - 1 - i))) <= k; --i)
		{
			if (val <= k && s[i] == '1')
			{
				val |= 1 << (N - 1 - i);
				++ones;
			}
		}
		return count(s.begin(), s.end(), '0') + ones;
	}
};