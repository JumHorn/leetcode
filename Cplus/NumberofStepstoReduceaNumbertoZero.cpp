
class Solution
{
public:
	int numberOfSteps(int num)
	{
		int res = (num == 0 ? 1 : 0);
		for (; num != 0; num >>= 1)
			res += 1 + (num & 1);
		return res - 1;
	}
};