/*
k+(k+1)+(k+2)+...+(k+m-1)=m*(2*k+m-1)/2=N
mk=N-m(m-1)/2
m和k一一对应，所以枚举m,m范围N-(m-1)*m>0
*/

class Solution
{
public:
	int consecutiveNumbersSum(int N)
	{
		int res = 0;
		for (int m = 1, mk = N; mk > 0; ++m, mk = N - (m - 1) * m / 2)
		{
			if (mk % m == 0)
				++res;
		}
		return res;
	}
};