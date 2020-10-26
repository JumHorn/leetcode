#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int thirdMax(vector<int> &nums)
	{
		long first, second, third;
		first = second = third = INT_MIN - 1L;
		for (auto n : nums)
		{
			if (n == first || n == second || n == third)
				continue;
			if (n > first)
			{
				third = second;
				second = first;
				first = n;
			}
			else if (n > second)
			{
				third = second;
				second = n;
			}
			else if (n > third)
				third = n;
		}
		return third >= INT_MIN ? third : first;
	}
};