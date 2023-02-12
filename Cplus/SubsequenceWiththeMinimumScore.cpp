#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumScore(string s, string t)
	{
		int M = s.size(), N = t.size();
		vector<int> prefix(M + 1), suffix(M + 1);
		for (int i = 0, j = 0; i < M && j < N; ++i)
		{
			if (s[i] == t[j])
			{
				prefix[i + 1] = prefix[i] + 1;
				++j;
			}
			else
				prefix[i + 1] = prefix[i];
		}
		for (int i = M - 1, j = N - 1; i >= 0 && j >= 0; --i)
		{
			if (s[i] == t[j])
			{
				suffix[i] = suffix[i + 1] + 1;
				--j;
			}
			else
				suffix[i] = suffix[i + 1];
		}
		int res = INT_MAX;
		for (int i = 0; i <= M; ++i)
			res = min(res, N - 1 - suffix[i] - prefix[i] + 1);
		return max(res, 0);
	}
};