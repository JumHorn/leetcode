#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countNicePairs(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		unordered_map<int, int> m; //{val-reverse(val),count}
		for (auto n : nums)
			res = (res + m[n - reverse(n)]++) % MOD;
		return res % MOD;
	}

	int reverse(int x)
	{
		int res = 0;
		for (; x > 0; x /= 10)
			res = res * 10 + x % 10;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};