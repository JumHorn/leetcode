#include <vector>
using namespace std;

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		make_heap(nums.begin(), nums.end());
		pop_heap(nums.begin(), nums.end());
		int a = nums.back();
		nums.pop_back();
		pop_heap(nums.begin(), nums.end());
		int b = nums.back();
		return (a - 1) * (b - 1);
	}
};
