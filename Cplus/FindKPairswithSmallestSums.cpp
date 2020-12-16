#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
	{
		auto f = [=](pair<int, int> &lhs, pair<int, int> &rhs) {
			return lhs.first + lhs.second < rhs.first + rhs.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);
		for (auto n1 : nums1)
		{
			for (auto n2 : nums2)
			{
				if ((int)q.size() >= k)
				{
					if (q.top().first + q.top().second <= n1 + n2)
						break;
					q.pop();
				}
				q.push({n1, n2});
			}
		}
		k = k > (int)q.size() ? q.size() : k;
		vector<vector<int>> res(k);
		for (int i = 0; i < k; ++i)
		{
			res[k - i - 1] = {q.top().first, q.top().second};
			q.pop();
		}
		return res;
	}
};