class Solution
{
public:
	int maxBottlesDrunk(int numBottles, int numExchange)
	{
		int res = numBottles, emptyBottles = numBottles;
		for (; numExchange <= emptyBottles; ++numExchange)
		{
			emptyBottles = emptyBottles - numExchange + 1;
			++res;
		}
		return res;
	}
};