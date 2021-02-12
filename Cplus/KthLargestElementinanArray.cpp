#include <algorithm>
#include <vector>
using namespace std;

/*
STL
1. nth_element
2. partial_sort
*/

class Solution
{
public:
	int findKthLargest(vector<int> &nums, int k)
	{
		nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
		//partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
		return nums[k - 1];
	}
};