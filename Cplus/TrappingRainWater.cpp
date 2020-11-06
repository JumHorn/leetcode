#include <algorithm>
#include <vector>
using namespace std;

// two pointers

class Solution
{
public:
	int trap(vector<int> &height)
	{
		int leftmax = 0, rightmax = 0, res = 0, N = height.size();
		for (int i = 0, j = N - 1; i < j;)
		{
			if (height[i] <= height[j])
			{
				res += max(0, leftmax - height[i]);
				leftmax = max(leftmax, height[i]);
				++i;
			}
			else
			{
				res += max(0, rightmax - height[j]);
				rightmax = max(rightmax, height[j]);
				--j;
			}
		}
		return res;
	}
};