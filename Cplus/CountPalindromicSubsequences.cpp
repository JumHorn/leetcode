#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countPalindromes(string s)
	{
		int N = s.size();
		vector<vector<vector<int>>> prefix(N, vector<vector<int>>(10, vector<int>(10)));
		vector<vector<vector<int>>> suffix(N, vector<vector<int>>(10, vector<int>(10)));
		vector<int> count_pre(10), count_suf(10);
		// prefix
		for (int i = 0; i < N; ++i)
		{
			int index = s[i] - '0';
			for (int a = 0; a < 10; ++a)
			{
				for (int b = 0; b < 10; ++b)
				{
					if (i > 0)
						prefix[i][a][b] = prefix[i - 1][a][b];
					if (index == b)
						prefix[i][a][b] = (count_pre[a] + prefix[i][a][b]) % MOD;
				}
			}
			++count_pre[index];
		}
		// suffix
		for (int i = N - 1; i >= 0; --i)
		{
			int index = s[i] - '0';
			for (int a = 0; a < 10; ++a)
			{
				for (int b = 0; b < 10; ++b)
				{
					if (i < N - 1)
						suffix[i][a][b] = suffix[i + 1][a][b];
					if (index == b)
						suffix[i][a][b] = (count_suf[a] + suffix[i][a][b]) % MOD;
				}
			}
			++count_suf[index];
		}

		int res = 0;
		for (int i = 1; i < N - 1; ++i)
		{
			for (int a = 0; a < 10; ++a)
			{
				for (int b = 0; b < 10; ++b)
					res = (res + (long)prefix[i - 1][a][b] * suffix[i + 1][a][b]) % MOD;
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};