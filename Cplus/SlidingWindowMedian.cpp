#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<double> medianSlidingWindow(vector<int> &nums, int k)
	{
		multiset<int> s;
		vector<double> res;
		for (int i = 0; i < k; ++i)
			s.insert(nums[i]);
		multiset<int>::iterator mid = next(s.begin(), k / 2);
		for (int i = k;; ++i)
		{
			res.push_back(((double)*mid + *prev(mid, 1 - k % 2)) / 2.0);
			if (i == (int)nums.size())
				break;
			s.insert(nums[i]);
			if (nums[i] < *mid)
				--mid;
			if (nums[i - k] <= *mid)
				++mid;
			s.erase(s.find(nums[i - k]));
		}
		return res;
	}
};