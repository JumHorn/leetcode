#include<algorithm>
using namespace std;

class Solution {
	static const int MOD = 1e9+7;
public:
    int nthMagicalNumber(int N, int A, int B) {
		long long lo=0,hi=1e15,mi;
		int L=A*B/gcd(A,B);
		while(lo<hi)
		{
			mi=(hi-lo)/2+lo;
			if(mi/A+mi/B-mi/L<N)
				lo=mi+1;
			else
				hi=mi;
		}
		return lo%MOD;
    }

	int gcd(int x,int y)
	{
		if(x==0)
			return y;
		return gcd(y%x,x);
	}
};
