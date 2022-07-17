#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumSum(vector<int> &nums)
	{
		unordered_map<int, int> m;
		int res = -1;
		for (auto n : nums)
		{
			int val = digitsSum(n);
			if (m.count(val) != 0)
				res = max(res, n + m[val]);
			m[val] = max(m[val], n);
		}
		return res;
	}

	int digitsSum(int n)
	{
		int res = 0;
		for (; n > 0; n /= 10)
			res += n % 10;
		return res;
	}
};