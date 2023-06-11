#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
	{
		int N1 = nums1.size(), N2 = nums2.size();
		auto f = [&](pair<int, int> &lhs, pair<int, int> &rhs)
		{
			return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);
		vector<vector<int>> res;
		for (int i = 0; i < N1; ++i)
			q.push({i, 0});
		while (--k >= 0 && !q.empty())
		{
			auto [i, j] = q.top();
			q.pop();
			res.push_back({nums1[i], nums2[j]});
			if (++j < N2)
				q.push({i, j});
		}
		return res;
	}
};