#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumSum(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		unordered_map<int, long long> m; //{normalised factor product,sum of values}
		for (int i = 0; i < N; ++i)
			res = max(res, m[normaliseInt(i + 1)] += nums[i]);
		return res;
	}

	int normaliseInt(int n)
	{
		int res = 1;
		for (int i = 2; i * i <= n; ++i)
		{
			int count = 0;
			for (; n % i == 0; n /= i)
				++count;
			if (count % 2 == 1)
				res *= i;
		}
		return res * n;
	}
};