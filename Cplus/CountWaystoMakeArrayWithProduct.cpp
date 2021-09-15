#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> waysToFillArray(vector<vector<int>> &queries)
	{
		int N = 10000, M = 13;
		int C[N + M][M + 1];
		C[0][0] = 1;
		for (int i = 1; i < N + M; ++i)
		{
			C[i][0] = 1;
			for (int j = 1; j <= i && j <= M; ++j)
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}

		vector<int> res;
		for (auto &q : queries)
		{
			int n = q[0], k = q[1];
			long long sum = 1;
			for (int i = 2; i * i <= k; ++i)
			{
				if (k % i == 0)
				{
					int j = 0;
					for (; k % i == 0; k /= i)
						++j;
					sum = sum * C[n + j - 1][j] % MOD; //combination with repetition
				}
			}
			if (k != 1) //A primer
				sum = sum * n % MOD;
			res.push_back(sum);
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};