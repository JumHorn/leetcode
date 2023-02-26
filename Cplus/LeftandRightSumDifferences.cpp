#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> leftRigthDifference(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> left(N), right(N);
		for (int i = 1; i < N; ++i)
			left[i] = left[i - 1] + nums[i - 1];
		for (int i = N - 2; i >= 0; --i)
			right[i] = right[i + 1] + nums[i + 1];
		vector<int> res;
		for (int i = 0; i < N; ++i)
			res.push_back(abs(left[i] - right[i]));
		return res;
	}
};