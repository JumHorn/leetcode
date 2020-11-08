#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &inventory, int orders)
	{
		int N = inventory.size(), res = 0;
		sort(inventory.begin(), inventory.end());
		for (int i = N - 1; i >= 0 && orders > 0; --i)
		{
			if (i == 0 || orders < long(N - i) * (inventory[i] - inventory[i - 1]))
			{
				int n = orders / (N - i);
				res = (res + long(N - i) * n * (inventory[i] + inventory[i] - n + 1) / 2) % MOD;
				int m = orders % (N - i);
				res = (res + (long)m * (inventory[i] - n)) % MOD;
				break;
			}
			orders -= (N - i) * (inventory[i] - inventory[i - 1]);
			res = (res + long(N - i) * (inventory[i] - inventory[i - 1]) * (inventory[i] + inventory[i - 1] + 1) / 2) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};