#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
	{
		unordered_map<string, int> index;
		for (auto &str : original)
		{
			if (index.find(str) == index.end())
				index[str] = index.size();
		}
		for (auto &str : changed)
		{
			if (index.find(str) == index.end())
				index[str] = index.size();
		}

		int N = index.size();
		vector<vector<long long>> dis(N, vector<long long>(N, LONG_MAX));

		for (int i = 0; i < cost.size(); ++i)
			dis[index[original[i]]][index[changed[i]]] = min(dis[index[original[i]]][index[changed[i]]], (long long)cost[i]);

		for (int k = 0; k < N; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				if (dis[i][k] == LONG_MAX) // a bit optimized code will run much faster
					continue;
				for (int j = 0; j < N; ++j)
				{
					if (dis[k][j] != LONG_MAX)
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}

		unordered_set<int> substrLengths;
		for (auto &str : original)
			substrLengths.insert(str.size());

		int M = source.size();
		vector<long long> dp(M + 1, LONG_MAX);
		dp[0] = 0;
		for (int i = 0; i < M; ++i)
		{
			if (dp[i] == LONG_MAX)
				continue;
			if (source[i] == target[i])
				dp[i + 1] = min(dp[i + 1], dp[i]);
			for (auto len : substrLengths)
			{
				if (i + len > M)
					continue;
				string subSource = source.substr(i, len);
				string subTarget = target.substr(i, len);
				int c1 = index.count(subSource) ? index[subSource] : -1;
				int c2 = index.count(subTarget) ? index[subTarget] : -1;
				if (c1 >= 0 && c2 >= 0 && dis[c1][c2] != LONG_MAX)
					dp[i + len] = min(dp[i + len], dp[i] + dis[c1][c2]);
			}
		}
		return dp[M] == LONG_MAX ? -1 : dp[M];
	}
};