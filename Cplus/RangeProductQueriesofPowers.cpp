#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> productQueries(int n, vector<vector<int>> &queries)
	{
		vector<long long> p;
		for (int i = 0; i <= 30; ++i)
		{
			if ((n >> i) & 1)
				p.push_back((1 << i) % MOD);
		}
		vector<int> res;
		for (auto &q : queries)
		{
			long long val = 1;
			for (int i = q[0]; i <= q[1]; ++i)
				val = val * p[i] % MOD;
			res.push_back(val);
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};