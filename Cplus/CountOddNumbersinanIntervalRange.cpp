
class Solution
{
public:
	int countOdds(int low, int high)
	{
		return ((high - low) + (low % 2 == 0 ? 1 : 0)) / 2 + low % 2;
	}
};
