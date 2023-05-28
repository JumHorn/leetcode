#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumCost(string s)
	{
		int N = s.size();
		vector<vector<long long>> prefix(N + 1, vector<long long>(2)), suffix(N + 1, vector<long long>(2));
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '0')
			{
				prefix[i + 1][0] = prefix[i][0];
				prefix[i + 1][1] = prefix[i][0] + (i + 1);
			}
			else
			{
				prefix[i + 1][0] = prefix[i][1] + (i + 1);
				prefix[i + 1][1] = prefix[i][1];
			}
		}
		for (int i = N - 1; i >= 0; --i)
		{
			if (s[i] == '0')
			{
				suffix[i][0] = suffix[i + 1][0];
				suffix[i][1] = suffix[i + 1][0] + (N - i);
			}
			else
			{
				suffix[i][0] = suffix[i + 1][1] + (N - i);
				suffix[i][1] = suffix[i + 1][1];
			}
		}
		long long res = min({prefix[N][0], prefix[N][1], suffix[0][0], suffix[0][1]});
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '0')
			{
				res = min(res, prefix[i][0] + suffix[i + 1][0]);									   // all 0
				res = min(res, min(prefix[i + 1][1] + suffix[i + 1][1], prefix[i][1] + suffix[i][1])); // all 1
			}
			else
			{
				res = min(res, prefix[i][1] + suffix[i + 1][1]);									   // all 1
				res = min(res, min(prefix[i + 1][0] + suffix[i + 1][0], prefix[i][0] + suffix[i][0])); // all 1
			}
		}
		return res;
	}
};