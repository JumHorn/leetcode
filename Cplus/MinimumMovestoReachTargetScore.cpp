class Solution
{
public:
	int minMoves(int target, int maxDoubles)
	{
		int res = 0;
		for (; target != 1 && maxDoubles > 0; ++res)
		{
			if (target % 2 == 0)
			{
				--maxDoubles;
				target /= 2;
			}
			else
				--target;
		}
		return res + target - 1;
	}
};