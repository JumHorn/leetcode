#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDeletions(vector<int> &nums)
	{
		int maxindex = 0, minindex = 0, N = nums.size();
		if (N == 1)
			return 1;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] > nums[maxindex])
				maxindex = i;
			if (nums[i] < nums[minindex])
				minindex = i;
		}
		int res = max(maxindex, minindex) + 1;
		res = min(res, N - min(maxindex, minindex));
		res = min(res, N - (max(maxindex, minindex) - min(maxindex, minindex) - 1));
		return res;
	}
};