#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> sumOfThree(long long num)
	{
		if ((num - 3) % 3 != 0)
			return {};
		long long start = (num - 3) / 3;
		return {start, start + 1, start + 2};
	}
};