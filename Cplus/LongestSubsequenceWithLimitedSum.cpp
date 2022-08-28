#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
	{
		sort(nums.begin(), nums.end());
		nums.push_back(0); //dummy node for simple coding
		int m = queries.size(), N = nums.size();
		vector<pair<int, int>> v; //{query,index}
		for (int i = 0; i < m; ++i)
			v.push_back({queries[i], i});
		sort(v.begin(), v.end());
		long long sum = 0;
		vector<int> res(m);
		for (int i = 0, j = 0; i < m; ++i)
		{
			for (; j < N && sum <= v[i].first; ++j)
				sum += nums[j];
			res[v[i].second] = j - 1;
		}
		return res;
	}
};