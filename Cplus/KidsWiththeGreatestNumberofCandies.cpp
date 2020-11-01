#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
	{
		int N = candies.size();
		vector<bool> res(N);
		int greatest = *max_element(candies.begin(), candies.end());
		for (int i = 0; i < N; ++i)
			res[i] = (extraCandies + candies[i] >= greatest);
		return res;
	}
};