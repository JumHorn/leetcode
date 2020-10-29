#include <vector>
using namespace std;

class Solution
{
public:
	int findJudge(int N, vector<vector<int>> &trust)
	{
		vector<int> degree(N + 1);
		for (auto &t : trust)
		{
			--degree[t[0]];
			++degree[t[1]];
		}
		for (int i = 1; i <= N; ++i)
		{
			if (degree[i] == N - 1)
				return i;
		}
		return -1;
	}
};