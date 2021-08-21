#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int twoCitySchedCost(vector<vector<int>> &costs)
	{
		int N = costs.size();
		vector<pair<int, int>> arr;
		for (int i = 0; i < N; ++i)
			arr.push_back({costs[i][1] - costs[i][0], i});
		nth_element(arr.begin(), arr.begin() + N / 2, arr.end());
		int res = 0;
		for (int i = 0; i < N / 2; ++i)
			res += costs[arr[i].second][1] + costs[arr[N / 2 + i].second][0];
		return res;
	}
};