#include <vector>
using namespace std;

class Solution
{
public:
	int maximumPrimeDifference(vector<int> &nums)
	{
		int first = -1, last = -1, N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (isPrimer(nums[i]))
			{
				last = i;
				if (first == -1)
					first = i;
			}
		}
		return last - first;
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