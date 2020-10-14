#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumMulti(vector<int> &A, int target)
	{
		long res = 0;
		vector<long> v(101);
		for (auto n : A)
			++v[n];
		for (int i = 0; i < 101; ++i)
		{
			for (int j = i; j < 101; ++j)
			{
				int k = target - i - j;
				if (k < 0 || k > 100)
					continue;
				if (i == j && j == k)
					res += v[i] * (v[i] - 1) * (v[i] - 2) / 6 % MOD;
				else if (i == j && j < k)
					res += v[i] * (v[i] - 1) / 2 * v[k] % MOD;
				else if (i < j && j == k)
					res += v[j] * (v[j] - 1) / 2 * v[i] % MOD;
				else if (i < j && j < k)
					res += v[i] * v[j] * v[k] % MOD;
			}
		}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};