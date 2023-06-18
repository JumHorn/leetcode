class Solution
{
public:
	int distanceTraveled(int mainTank, int additionalTank)
	{
		int res = 0;
		while (mainTank >= 5)
		{
			int p = mainTank / 5;
			int q = mainTank % 5;
			res += p * 10 * 5;
			if (p >= additionalTank)
			{
				mainTank = q + additionalTank;
				additionalTank = 0;
			}
			else
			{
				mainTank = q + p;
				additionalTank -= p;
			}
		}
		return res + mainTank * 10;
	}
};