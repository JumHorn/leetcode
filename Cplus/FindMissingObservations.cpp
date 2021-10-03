#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> missingRolls(vector<int> &rolls, int mean, int n)
	{
		int m = rolls.size();
		int sum = mean * (m + n);
		int sum1 = accumulate(rolls.begin(), rolls.end(), 0);
		sum -= sum1;
		if (sum < n || sum > 6 * n)
			return {};
		vector<int> res(n, 1);
		sum -= n;
		for (int i = 0; sum > 0 && i < n; ++i)
		{
			int val = min(5, sum);
			res[i] = val + 1;
			sum -= val;
		}
		return res;
	}
};