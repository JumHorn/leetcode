#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumMulti(vector<int> &A, int target)
	{
		if ((int)A.size() < 3)
			return 0;
		vector<long> v(101);
		for (int i = 0; i < (int)A.size(); i++)
			++v[A[i]];
		long res = 0;
		for (int i = 0; i < (int)v.size(); i++)
			for (int j = 0; j < (int)v.size(); j++)
			{
				int k = target - i - j;
				if (k < 0 || k > 100 || v[k] == 0 || v[i] == 0 || v[j] == 0)
					continue;
				if (i == j && j == k)
					res += v[i] * (v[i] - 1) * (v[i] - 2) / 6 % MOD;
				else if (i == j && j != k)
					res += v[i] * (v[i] - 1) / 2 * v[k] % MOD;
				else if (i < j && j < k)
					res += v[i] * v[j] * v[k] % MOD;
			}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};

