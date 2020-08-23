#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxCoins(vector<int>& piles)
	{
		sort(piles.begin(), piles.end());
		int res = 0, N = piles.size();
		for (int i = N - 1; i > N / 3; i -= 2)
			res += piles[i - 1];
		return res;
	}
};
