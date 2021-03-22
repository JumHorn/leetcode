#include <climits>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string shortestSuperstring(vector<string> &A)
	{
		const int N = A.size();
		vector<vector<int>> graph(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				graph[i][j] = overlap(A[i], A[j]);
		}

		//TSP DP build shortest path
		vector<vector<int>> dp(1 << N, vector<int>(N, 1e9));
		vector<vector<int>> path(1 << N, vector<int>(N));
		for (int i = 1; i < (1 << N); ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if ((i & (1 << j)) == 0)
					continue;
				int pre = i ^ (1 << j);
				if (pre == 0)
					dp[i][j] = A[j].length();
				else
				{
					for (int k = 0; k < N; ++k)
					{
						if ((pre & (1 << k)) != 0 && dp[pre][k] + graph[k][j] < dp[i][j])
						{
							dp[i][j] = dp[pre][k] + graph[k][j];
							path[i][j] = k;
						}
					}
				}
			}
		}

		// build path
		int last, minlen = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (dp[(1 << N) - 1][i] < minlen)
			{
				minlen = dp[(1 << N) - 1][i];
				last = i;
			}
		}

		stack<int> s;
		int nodes = (1 << N) - 1;
		while (nodes > 0)
		{
			s.push(last);
			int tmp = nodes;
			nodes -= (1 << last);
			last = path[tmp][last];
		}
		int index, previous = s.top();
		string res = A[previous];
		s.pop();
		while (!s.empty())
		{
			index = s.top();
			s.pop();
			res += A[index].substr(A[index].length() - graph[previous][index]);
			previous = index;
		}
		return res;
	}

	int overlap(string &a, string &b)
	{
		int k = 0, N = a.length();
		for (k = 1; k < N; ++k)
		{
			int i = k, j = 0;
			while (i < N && a[i] == b[j])
				++i, ++j;
			if (i == N)
				break;
		}
		return b.length() - a.length() + k;
	}
};