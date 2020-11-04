
class Solution
{
public:
	char findKthBit(int n, int k)
	{
		bool flip = false;
		while (n > 1)
		{
			if (k == (1 << (n - 1)))
			{
				flip = !flip;
				break;
			}
			if (k > (1 << (n - 1)))
			{
				flip = !flip;
				k = (1 << n) - k;
			}
			else
				--n;
		}
		return flip ? '1' : '0';
	}
};