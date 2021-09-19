#include <vector>
using namespace std;

/*
even means the maximum alternating sum ending with a even index
odd means the maximum alternating sum ending with a odd index
*/

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