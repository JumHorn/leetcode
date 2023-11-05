#include <vector>
using namespace std;

class Solution
{
public:
	int findChampion(int n, vector<vector<int>> &edges)
	{
		vector<int> degree(n);
		for (auto &edge : edges)
			++degree[edge[1]];
		int res = -1, count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (degree[i] == 0)
			{
				++count;
				res = i;
			}
		}
		return count == 1 ? res : -1;
	}
};