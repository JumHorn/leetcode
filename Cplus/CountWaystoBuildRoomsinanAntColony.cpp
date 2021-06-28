#include <vector>
using namespace std;

class Solution
{
public:
	int waysToBuildRooms(vector<int> &prevRoom)
	{
		int N = prevRoom.size();
		vector<vector<int>> graph(N);
		for (int i = 1; i < N; ++i)
			graph[prevRoom[i]].push_back(i);

		// Pre-process fac and inv fac.
		vector<long long> fac(N + 1, 1), ifac(N + 1, 1);
		for (int i = 2; i <= N; ++i)
		{
			fac[i] = fac[i - 1] * i % MOD;
			ifac[i] = modPow(fac[i], MOD - 2);
		}

		return postorder(graph, 0, fac, ifac).second;
	}
	//{node count,combinations for subtree}
	pair<int, long> postorder(vector<vector<int>> &graph, int at, vector<long long> &fac, vector<long long> &ifac)
	{
		if (graph[at].empty())
			return {1, 1};
		pair<int, int> res = {0, 1};
		for (auto to : graph[at])
		{
			auto tmp = postorder(graph, to, fac, ifac);
			long long comb = (((fac[res.first + tmp.first] * ifac[res.first]) % MOD) * ifac[tmp.first]) % MOD;
			res.second = (comb * res.second % MOD) * tmp.second % MOD;
			res.first += tmp.first;
		}
		++res.first;
		return res;
	}

	long long modPow(long long x, int n)
	{
		long long res = 1;
		for (auto i = n; i > 0; i /= 2)
		{
			if (i % 2)
				res = res * x % MOD;
			x = x * x % MOD;
		}
		return res;
	}

	// int combination(int n, int m)
	// {
	// 	long res = 1;
	// 	for (int i = 1; i <= m; ++i)
	// 		res = res * (n - m + i) / i % MOD;
	// 	return res;
	// }

private:
	static const int MOD = 1e9 + 7;
};