#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFlips(string s)
	{
		int N = s.length();
		vector<vector<int>> prefix(N, vector<int>(2)), suffix(N, vector<int>(2)); //{start with 0,start with 1}
		prefix[0][0] = s[0] - '0';
		prefix[0][1] = 1 - (s[0] - '0');
		for (int i = 1; i < N; ++i)
		{
			prefix[i][0] = s[i] - '0' + prefix[i - 1][1];
			prefix[i][1] = 1 - (s[i] - '0') + prefix[i - 1][0];
		}
		suffix[N - 1][0] = s[N - 1] - '0';
		suffix[N - 1][1] = 1 - (s[N - 1] - '0');
		for (int i = N - 2; i >= 0; --i)
		{
			suffix[i][0] = s[i] - '0' + suffix[i + 1][1];
			suffix[i][1] = 1 - (s[i] - '0') + suffix[i + 1][0];
		}

		int res = min(suffix[0][0], suffix[0][1]);
		for (int i = 1; i < N; ++i)
		{
			res = min({res, suffix[i][0] + prefix[i - 1][1 - N % 2], suffix[i][1] + prefix[i - 1][N % 2]});
		}
		return res;
	}
};