class Solution
{
public:
	int minimizeXor(int num1, int num2)
	{
		int n1 = bitCount(num1), n2 = bitCount(num2);
		if (n2 <= n1) //remove from MLB
		{
			int count = n1 - n2;
			for (int i = 0; i <= 30 && count > 0; ++i)
			{
				if ((num1 >> i) & 1)
				{
					num1 ^= (1 << i);
					--count;
				}
			}
		}
		else //make num1 0 bit from LMB
		{
			int count = n2 - n1;
			for (int i = 0; i <= 30 && count > 0; ++i)
			{
				if (((num1 >> i) & 1) == 0)
				{
					num1 ^= (1 << i);
					--count;
				}
			}
		}
		return num1;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};