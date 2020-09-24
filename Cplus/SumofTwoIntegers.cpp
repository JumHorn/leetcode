
class Solution
{
public:
	int getSum(int a, int b)
	{
		unsigned int carry = (a & b), sum = a ^ b;
		return carry == 0 ? sum : getSum(sum, carry << 1);
	}
};