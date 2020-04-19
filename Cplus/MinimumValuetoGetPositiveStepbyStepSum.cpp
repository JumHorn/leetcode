#include <vector>
using namespace std;

class Solution
{
public:
	int minStartValue(vector<int>& nums)
	{
		int sum = 1, startValue = 1;
		for (auto n : nums)
		{
			sum += n;
			if (sum < 1)
			{
				startValue += 1 - sum;
				sum = 1;
			}
		}
		return startValue;
	}
};
