
class Solution
{
public:
	int bitwiseComplement(int N)
	{
		return N == 0 ? 1 : (getMask(N) & ~N);
	}

	int getMask(int n) //flip all bit to 1
	{
		n |= (n >> 1);
		n |= (n >> 2);
		n |= (n >> 4);
		n |= (n >> 8);
		n |= (n >> 16);
		return n;
	}
};