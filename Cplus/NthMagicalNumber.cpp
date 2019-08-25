#include<algorithm>
using namespace std;

class Solution {
	static const int MOD = 1e9+7;
public:
    int nthMagicalNumber(int N, int A, int B) {
		if(A>B)
			swap(A,B);			
		if(N==1)
			return A;
		if(B%A==0)
			return (long long)A*(long long)N%MOD;
		long long head=A,a=A,b=0;
		for(int i=1;i<N;)
		{
			long long tmp=min(a+A,b+B);
			if(tmp==a+A)
				a=(a+A)%MOD;
			if(tmp==b+B)
				b=(b+B)%MOD;
			if(tmp!=head)
            {
                head=tmp;
				i++;
            }
		}
		return head%MOD;
    }
};
