class Solution
{
public:
	int reachNumber(int target)
	{
		if (target < 0)
			target = -target;
		int steps = 0;
		while (target > 0)
			target -= ++steps;
		return target % 2 == 0 ? steps : steps + 1 + steps % 2;
	}
};