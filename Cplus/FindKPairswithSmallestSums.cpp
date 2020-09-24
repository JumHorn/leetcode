#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
	{
		auto f = [=](pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.first + lhs.second < rhs.first + rhs.second; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);
		for (int i = 0; i < (int)nums1.size(); i++)
		{
			for (int j = 0; j < (int)nums2.size(); j++)
			{
				if ((int)q.size() < k)
					q.push({nums1[i], nums2[j]});
				else
				{
					if (q.top().first + q.top().second <= nums1[i] + nums2[j])
						break;
					q.pop();
					q.push({nums1[i], nums2[j]});
				}
			}
		}
		k = k > (int)q.size() ? q.size() : k;
		vector<vector<int>> res(k);
		for (int i = 0; i < k; i++)
		{
			res[k - i - 1] = {q.top().first, q.top().second};
			q.pop();
		}
		return res;
	}
};