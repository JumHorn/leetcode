#include <algorithm>
#include <vector>
using namespace std;

/*
First, if there's no zero in the array,
then the subarray with maximum product must start with the first element or end with the last element

Second if there are zeros in the array,
the zero bounded subarray meets the first requirement

Algorithm:
the result must exists in the prefix product or suffix product of the array
*/

class Solution
{
public:
	int maxProduct(vector<int> &nums)
	{
		int N = nums.size(), res = nums[0], prefixproduct = 0, suffixproduct = 0;
		for (int i = 0; i < N; ++i)
		{
			prefixproduct = (prefixproduct != 0 ? prefixproduct : 1) * nums[i];
			suffixproduct = (suffixproduct != 0 ? suffixproduct : 1) * nums[N - 1 - i];
			res = max(res, max(prefixproduct, suffixproduct));
		}
		return res;
	}
};