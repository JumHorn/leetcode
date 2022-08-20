#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
	{
		int N = nums.size();
		vector<long long> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];

		vector<long long> res;
		vector<int> length(N + 2);
		res.push_back(0);
		for (int i = N - 1; i > 0; --i)
		{
			int a = removeQueries[i], left = (a > 0 ? length[a - 1] : 0), right = length[a + 1];
			length[a - left] = length[a + right] = left + right + 1;
			res.push_back(max(res.back(), prefixsum[a + right + 1] - prefixsum[a - left]));
		}
		reverse(res.begin(), res.end());
		return res;
	}
};