#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumCost(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<long long> v = nearestPalindromic(nums[N / 2]);
		long long res = LLONG_MAX;
		for (auto n : v)
			res = min(res, cost(nums, n));

		if (N % 2 == 0)
		{
			vector<long long> v = nearestPalindromic(nums[(N - 1) / 2]);
			for (auto n : v)
				res = min(res, cost(nums, n));
		}
		return res;
	}

	vector<long long> nearestPalindromic(int x)
	{
		string n = to_string(x);
		int N = n.length();
		n[(N + 1) / 2] = '\0';
		long half = stoll(n.substr(0, (N + 1) / 2));
		long res0 = makePalindrome(half, N % 2);

		long res1;
		if (half != pow(10, (N + 1) / 2) - 1)
			res1 = makePalindrome(half + 1, N % 2);
		else
			res1 = pow(10, N) + 1;

		long res2;
		if (half != pow(10, (N + 1) / 2 - 1))
			res2 = makePalindrome(half - 1, N % 2);
		else
			res2 = pow(10, N - 1) - 1;

		return {res0, res1, res2};
	}

	long makePalindrome(long half, int even)
	{
		long left = half, right = 0;
		if (even != 0)
			half /= 10;
		for (; half > 0; half /= 10)
		{
			left *= 10;
			right = right * 10 + half % 10;
		}
		return left + right;
	}

	long long cost(vector<int> &nums, int x)
	{
		long long res = 0;
		for (auto n : nums)
			res += abs(n - x);
		return res;
	}
};