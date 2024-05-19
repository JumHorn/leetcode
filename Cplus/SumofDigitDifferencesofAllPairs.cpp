#include <vector>
using namespace std;

class Solution
{
public:
	long long sumDigitDifferences(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		for (long long base = 1; nums[0] / base > 0; base *= 10)
		{
			vector<int> count(10);
			for (int i = 0; i < N; ++i)
				res += i - count[nums[i] / base % 10]++;
		}
		return res;
	}
};