#include <cstring> //for memset
#include <string>
#include <vector>
using namespace std;

// next permutation

class Solution
{
public:
	int makeStringSorted(string s)
	{
		int N = s.length();
		// combination table
		// vector<vector<int>> combination(N + 1, vector<int>(N + 1));
		int combination[3001][3001];
		memset(combination, 0, sizeof(combination));
		combination[0][0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			combination[i][0] = combination[i][i] = 1;
			for (int j = 1; j <= i / 2; ++j)
				combination[i][j] = combination[i][i - j] = (combination[i - 1][j] + combination[i - 1][j - 1]) % MOD;
		}

		vector<int> count(26);
		for (auto c : s)
			++count[c - 'a'];
		int res = 0, n = N;
		for (auto c : s)
		{
			for (char a = c - 1; a >= 'a'; --a)
			{
				long k = n - 1, m = 1;
				if (count[a - 'a'] != 0)
				{
					--count[a - 'a'];
					for (int i = 0; i < 26; ++i)
					{
						m = m * (combination[k][count[i]]) % MOD;
						k -= count[i];
					}
					++count[a - 'a'];
					res = (res + m) % MOD;
				}
			}
			--count[c - 'a'];
			--n;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};