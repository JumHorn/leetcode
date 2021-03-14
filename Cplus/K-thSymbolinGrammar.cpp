class Solution
{
public:
	int kthGrammar(int N, int K)
	{
		int res = 0;
		for (; K > 1; K = (K + 1) >> 1)
			res ^= 1 ^ (K & 1);
		return res;
	}
};