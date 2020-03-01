#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfSubarrays(vector<int> &nums, int k)
	{
		int res = 0, odd = 0, n = nums.size();
		if (k > n)
			return res;
		for (int i = 0; i < n; i++)
			nums[i] = nums[i] % 2;
		int i, j;
		for (i = 0; i < n; i++)
		{
			odd += nums[i];
			if (odd >= k)
				break;
		}
		for (j = 0; i < n;)
		{
			int right = i + 1;
			while (right < n && nums[right] != 1)
				++right;
			int left = j;
			while (left < n && nums[left] != 1)
				++left;
			res += (left - j + 1) * (right - i);
			i = right;
			j = left + 1;
		}
		return res;
	}
};