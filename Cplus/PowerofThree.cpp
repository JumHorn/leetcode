/*
pow(3,19) == 1162261467
pow(3,19) < INT_MAX
*/

class Solution
{
public:
	bool isPowerOfThree(int n)
	{
		return n > 0 && 1162261467 % n == 0;
	}
};