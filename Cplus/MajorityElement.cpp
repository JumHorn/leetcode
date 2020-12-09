#include <unordered_map>
#include <vector>
using namespace std;

/*
Boyer–Moore majority vote algorithm
*/

class Solution
{
public:
	int majorityElement(vector<int> &nums)
	{
		int val = 0, count = 0;
		for (auto n : nums)
		{
			if (val == n)
				++count;
			else if (count == 0)
			{
				val = n;
				count = 1;
			}
			else
				--count;
		}
		return val;
	}
};