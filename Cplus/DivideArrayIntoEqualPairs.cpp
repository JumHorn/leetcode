#include <vector>
using namespace std;

class Solution
{
public:
	bool divideArray(vector<int> &nums)
	{
		vector<int> count(501);
		for (auto n : nums)
			++count[n];
		for (auto n : count)
		{
			if (n % 2 == 1)
				return false;
		}
		return true;
	}
};