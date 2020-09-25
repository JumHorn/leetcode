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
		for (int i = 0; i <= 9; ++i)
		{
			if (value + i > n || value % 10 + i >= 10)
				break;
			res.push_back(value + i);
			dfs(n, (value + i) * 10, res);
		}
	}
};