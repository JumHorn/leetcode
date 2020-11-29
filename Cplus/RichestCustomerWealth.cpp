#include <vector>
using namespace std;

class Solution
{
public:
	int maximumWealth(vector<vector<int>> &accounts)
	{
		int res = 0;
		for (auto account : accounts)
		{
			int money = 0;
			for (auto n : account)
				money += n;
			res = max(res, money);
		}
		return res;
	}
};