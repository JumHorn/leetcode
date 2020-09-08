
/*
Combination(2n,2) choose 2 pair from 2n pairs
n pairs can be any order
res=Combination(2n,2)*Combination(2(n-1),2)*****Combination(2(1),2)
*/

int countOrders(int n)
{
	static const int MOD = 1e9 + 7;
	long res = 1;
	while (n > 0)
	{
		res = (res * n * (2 * n - 1)) % MOD;
		--n;
	}
	return res;
}