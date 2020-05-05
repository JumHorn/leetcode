#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
	{
		int n = candies.size();
		vector<bool> res(n);
		int most = *max_element(candies.begin(), candies.end());
		for (int i = 0; i < n; i++)
			res[i] = (extraCandies + candies[i]) >= most;
		return res;
	}
};
