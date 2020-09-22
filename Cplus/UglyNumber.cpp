class Solution
{
public:
	bool isUgly(int num)
	{
		if (num < 0)
			return false;
		num = divide(num, 2);
		num = divide(num, 3);
		num = divide(num, 5);
		return num == 1;
	}

	int divide(int num, int d)
	{
		while (num != 0 && num % d == 0)
			num /= d;
		return num;
	}
};