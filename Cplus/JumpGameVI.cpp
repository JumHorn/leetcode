#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxResult(vector<int> &nums, int k)
	{
		int N = nums.size();
		deque<pair<int, int>> q;
		q.push_back({0, nums[0]});
		for (int i = 1; i < N; ++i)
		{
			while (!q.empty() && i - q.front().first > k)
				q.pop_front();
			int val = nums[i] + q.front().second;
			while (!q.empty() && val > q.back().second)
				q.pop_back();
			q.push_back({i, val});
		}
		return q.back().second;
	}
};