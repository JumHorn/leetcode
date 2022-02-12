#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> pivotArray(vector<int> &nums, int pivot)
	{
		vector<int> left, mid, right;
		for (auto n : nums)
		{
			if (n < pivot)
				left.push_back(n);
			else if (n > pivot)
				right.push_back(n);
			else
				mid.push_back(n);
		}
		left.insert(left.end(), mid.begin(), mid.end());
		left.insert(left.end(), right.begin(), right.end());
		return left;
	}
};