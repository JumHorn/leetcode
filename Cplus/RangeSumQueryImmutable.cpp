#include <vector>
using namespace std;

class NumArray
{
public:
	NumArray(vector<int> &nums) : prefixsum(nums.size() + 1)
	{
		for (int i = 0; i < (int)nums.size(); ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];
	}

	int sumRange(int i, int j)
	{
		return prefixsum[j + 1] - prefixsum[i];
	}

private:
	vector<int> prefixsum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */