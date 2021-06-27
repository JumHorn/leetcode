#include <vector>
using namespace std;

class Solution
{
public:
	long long maxAlternatingSum(vector<int> &nums)
	{
		long long even = 0, odd = 0;
		for (auto n : nums)
		{
			even = max(even, odd + n);
			odd = even - n;
		}
		return even;
	}
};