#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> mostCompetitive(vector<int> &nums, int k)
	{
		int N = nums.size();
		deque<int> q;
		for (int i = 0; i < N; ++i)
		{
			while (!q.empty() && (q.size() + N - i > k) && nums[i] < q.back())
				q.pop_back();
			if (q.size() < k)
				q.push_back(nums[i]);
		}
		return vector<int>(q.begin(), q.end());
	}
};