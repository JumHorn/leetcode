#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long findTheArrayConcVal(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		for (int i = 0; i < N / 2; ++i)
			res += stoll(to_string(nums[i]) + to_string(nums[N - 1 - i]));
		if (N % 2 != 0)
			res += nums[N / 2];
		return res;
	}
};