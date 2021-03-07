class Solution
{
public:
	bool checkPowersOfThree(int n)
	{
		int three = 1;
		while (three <= n)
			three *= 3;
		while (n != 0 && three != 0)
		{
			three /= 3;
			if (n >= three)
				n -= three;
		}
		return n == 0;
	}
};