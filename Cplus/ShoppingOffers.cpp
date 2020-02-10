#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
	{
		int res = 0;
		for (int i = 0; i < (int)needs.size(); i++)
			res += needs[i] * price[i];
		for (int i = 0; i < (int)special.size(); i++)
		{
			vector<int> tmp(needs);
			bool flag = true;
			for (int j = 0; j < (int)tmp.size(); j++)
			{
				tmp[j] -= special[i][j];
				if (tmp[j] < 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				res = min(res, shoppingOffers(price, special, tmp) + special[i].back());
		}
		return res;
	}
};