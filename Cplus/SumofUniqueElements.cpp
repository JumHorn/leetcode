#include <vector>
using namespace std;

class Solution
{
public:
	int sumOfUnique(vector<int> &nums)
	{
		int res = 0;
		vector<int> count(101);
		for (auto n : nums)
			++count[n];
		for (int i = 0; i <= 100; ++i)
		{
			if (count[i] == 1)
				res += i;
		}
		return res;
	}
};