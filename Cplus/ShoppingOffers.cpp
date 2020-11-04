#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
	{
		int res = 0, N = needs.size();
		for (int i = 0; i < N; ++i)
			res += needs[i] * price[i];
		for (auto &sp : special)
		{
			vector<int> newneeds(needs);
			int j;
			for (j = 0; j < N; ++j)
			{
				newneeds[j] -= sp[j];
				if (newneeds[j] < 0)
					break;
			}
			if (j == N)
				res = min(res, shoppingOffers(price, special, newneeds) + sp.back());
		}
		return res;
	}
};