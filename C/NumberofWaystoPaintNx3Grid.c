/*
所有颜色的状态相同，且对称
故将分为两类，两种颜色(c121)和三种颜色(c123)
状态机
	    __3*c121
c121---|
	   |__2*c123

	    __2*c121
c123---|
	   |__2*c123
*/

int numOfWays(int n)
{
	static const int MOD = 1e9 + 7;
	long two = 6, three = 6;
	for (int i = 1; i < n; ++i)
	{
		long two1 = two * 3 % MOD + three * 2 % MOD;
		long three1 = two * 2 % MOD + three * 2 % MOD;
		two = two1 % MOD;
		three = three1 % MOD;
	}
	return (two + three) % MOD;
}
