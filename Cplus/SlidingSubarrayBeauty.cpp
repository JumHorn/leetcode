#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
	{
		vector<int> count(101);
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < k; ++i)
			++count[nums[i] + 50];
		res.push_back(xthElement(count, x) - 50);
		for (int i = k; i < N; ++i)
		{
			++count[nums[i] + 50];
			--count[nums[i - k] + 50];
			res.push_back(xthElement(count, x) - 50);
		}
		for (auto &n : res)
		{
			if (n > 0)
				n = 0;
		}
		return res;
	}

	int xthElement(vector<int> &v, int x)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			x -= v[i];
			if (x <= 0)
				return i;
		}
		return 0;
	}
};