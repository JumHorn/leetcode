
class Solution
{
public:
	bool hasAlternatingBits(int n)
	{
		n = (n >> 2) ^ n; //only one bit left in n
		return (n & (n - 1)) == 0;
	}
};