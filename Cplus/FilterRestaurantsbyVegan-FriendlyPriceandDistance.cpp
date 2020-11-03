#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
	{
		vector<vector<int>> filter;
		for (int i = 0; i < (int)restaurants.size(); ++i)
		{
			if (restaurants[i][2] < veganFriendly)
				continue;
			if (restaurants[i][3] > maxPrice)
				continue;
			if (restaurants[i][4] > maxDistance)
				continue;
			filter.push_back(restaurants[i]);
		}
		sort(filter.begin(), filter.end(), *this);
		vector<int> res;
		for (int i = 0; i < (int)filter.size(); ++i)
			res.push_back(filter[i][0]);
		return res;
	}

	bool operator()(const vector<int> &lhs, const vector<int> &rhs)
	{
		if (lhs[1] != rhs[1])
			return lhs[1] > rhs[1];
		return lhs[0] > rhs[0];
	}
};
