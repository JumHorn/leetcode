#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> resultArray(vector<int> &nums)
	{
		vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
		int N = nums.size();
		for (int i = 2; i < N; ++i)
		{
			if (arr1.back() > arr2.back())
				arr1.push_back(nums[i]);
			else
				arr2.push_back(nums[i]);
		}
		for (auto n : arr2)
			arr1.push_back(n);
		return arr1;
	}
};