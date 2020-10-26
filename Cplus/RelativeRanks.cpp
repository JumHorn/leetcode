#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findRelativeRanks(vector<int> &nums)
	{
		vector<pair<int, int>> v; //{score,index}
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			v.push_back({nums[i], i});
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		vector<string> winner = {"Gold Medal", "Silver Medal", "Bronze Medal"}, res(N);
		for (int i = 0; i < min(3, N); ++i)
			res[v[i].second] = winner[i];
		for (int i = 3; i < N; ++i)
			res[v[i].second] = to_string(i + 1);
		return res;
	}
};