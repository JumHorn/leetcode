class Solution
{
public:
	int sumOfTheDigitsOfHarshadNumber(int x)
	{
		int res = sumOfDigits(x);
		if (x % res != 0)
			return -1;
		return res;
	}

	int sumOfDigits(int n)
	{
		int res = 0;
		for (; n > 0; n /= 10)
			res += n % 10;
		return res;
	}
};