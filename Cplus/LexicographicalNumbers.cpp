#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> lexicalOrder(int n)
	{
		vector<int> res;
		dfs(n, 1, res);
		return res;
	}

	void dfs(int n, int value, vector<int> &res)
	{
		if (value > n)
			return;
		res.push_back(value);
		if (value * 10 > n)
		{
			for (int i = 1; value % 10 + i < 10 && value + i <= n; ++i)
				res.push_back(value + i);
			return;
		}
		dfs(n, value * 10, res);
		if (value % 10 != 9)
			dfs(n, value + 1, res);
	}
};