#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestVariance(string s)
	{
		int res = 0, N = s.length();
		vector<int> prefix(N + 1), suffix(N + 1);
		for (char i = 'a'; i <= 'z'; ++i)
		{
			for (char j = 'a'; j <= 'z'; ++j)
			{
				if (i != j)
					res = max(res, variance(s, i, j, prefix, suffix));
			}
		}
		return res;
	}

	int variance(string s, char a, char b, vector<int> &prefix, vector<int> &suffix)
	{
		//choose b as the only b
		int res = 0, N = s.length();
		prefix[0] = suffix[N] = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == a)
				prefix[i + 1] = max(prefix[i], 0) + 1;
			else if (s[i] == b)
				prefix[i + 1] = max(prefix[i] - 1, 0);
			else
				prefix[i + 1] = prefix[i];

			if (s[N - 1 - i] == a)
				suffix[N - 1 - i] = max(suffix[N - i], 0) + 1;
			else if (s[N - 1 - i] == b)
				suffix[N - 1 - i] = max(suffix[N - i] - 1, 0);
			else
				suffix[N - 1 - i] = suffix[N - i];
		}
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == b)
				res = max(res, prefix[i] + suffix[i + 1] - 1);
		}
		return res;
	}
};