#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findGCD(vector<int> &nums)
	{
		int a = *max_element(nums.begin(), nums.end());
		int b = *min_element(nums.begin(), nums.end());
		return gcd(a, b);
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};