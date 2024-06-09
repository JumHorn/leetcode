#include <vector>
using namespace std;

class Solution
{
public:
	int valueAfterKSeconds(int n, int k)
	{
		vector<long long> sum(n, 1);
		for (int i = 0; i < k; ++i)
		{
			for (int j = 1; j < n; ++j)
				sum[j] = (sum[j - 1] + sum[j]) % MOD;
		}
		return sum.back();
	}

private:
	static const int MOD = 1e9 + 7;
};