#include <vector>
using namespace std;

class Solution
{
public:
	int diagonalPrime(vector<vector<int>> &nums)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (isPrimer(nums[i][i]))
				res = max(res, nums[i][i]);
			if (isPrimer(nums[i][N - 1 - i]))
				res = max(res, nums[i][N - 1 - i]);
		}
		return res;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (long long i = 2; i * i <= N; ++i)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
};