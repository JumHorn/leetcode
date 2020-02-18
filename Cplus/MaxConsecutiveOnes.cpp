#include <vector>
using namespace std;

class Solution
{
public:
	int findMaxConsecutiveOnes(vector<int>& nums)
	{
		int sum = 0, tmp = 0;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		{
			if (*iter == 0)
			{
				if (tmp > sum)
					sum = tmp;
				tmp = 0;
			}
			else
			{
				tmp++;
			}
		}
		return sum > tmp ? sum : tmp;
	}
};
