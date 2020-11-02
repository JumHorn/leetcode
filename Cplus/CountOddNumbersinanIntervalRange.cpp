
class Solution
{
public:
	int countOdds(int low, int high)
	{
		int n = high - low + 1;
		return n / 2 + (n % 2 == 0 ? 0 : low % 2);
	}
};