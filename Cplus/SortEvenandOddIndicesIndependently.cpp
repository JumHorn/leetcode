#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortEvenOdd(vector<int> &nums)
	{
		vector<int> odd, even;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
				even.push_back(nums[i]);
			else
				odd.push_back(nums[i]);
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end(), greater<int>());
		vector<int> res;
		for (int i = 0, j = 0, k = 0; i < N; ++i)
		{
			if (i % 2 == 0)
				res.push_back(even[j++]);
			else
				res.push_back(odd[k++]);
		}
		return res;
	}
};