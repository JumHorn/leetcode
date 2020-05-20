#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
	vector<double> medianSlidingWindow(vector<int> &nums, int k)
	{
		multiset<int> s;
		vector<double> res;
		for (int i = 0; i < k; i++)
			s.insert(nums[i]);
		multiset<int>::iterator right = s.begin(), left;
		advance(right, k / 2);
		left = right;
		advance(left, k % 2 - 1);
		res.push_back(((double)*left + *right) / 2.0);
		for (int i = k; i < (int)nums.size(); i++)
		{
			s.insert(nums[i]);
			s.erase(s.find(nums[i - k]));
			right = s.begin();
			advance(right, k / 2);
			left = right;
			advance(left, k % 2 - 1);
			res.push_back(((double)*left + *right) / 2.0);
		}
		return res;
	}
};