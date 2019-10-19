#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
		int res=0,MOD=1e9+7,N=A.size();
        sort(A.begin(),A.end());
		long *pow2=new long[A.size()];
		pow2[0]=1;
		for(int i=1;i<N;i++)
			pow2[i]=pow2[i-1]*2%MOD;
		for(int i=0;i<N;i++)
			res=(res+(pow2[i]-pow2[N-i-1])*A[i])%MOD;
		return res;
    }
};

