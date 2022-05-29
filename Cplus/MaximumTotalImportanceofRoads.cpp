#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumImportance(int n, vector<vector<int>> &roads)
	{
		vector<long long> degree(n);
		for (auto &road : roads)
		{
			++degree[road[0]];
			++degree[road[1]];
		}
		sort(degree.begin(), degree.end());
		long long value = 1, res = 0;
		for (auto n : degree)
			res += value++ * n;
		return res;
	}
};