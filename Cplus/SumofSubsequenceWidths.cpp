#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
		int res=0,MOD=1e9+7;
        sort(A.begin(),A.end());
		long *pow2=new long[A.size()];
		pow2[0]=1;
		for(int i=1;i<(int)A.size();i++)
			pow2[i]=pow2[i-1]*2%MOD;
		for(int i=0;i<(int)A.size()-1;i++)
			for(int j=i+1;j<(int)A.size();j++)
				res=(res+pow2[j-i-1]*(A[j]-A[i]))%MOD;
		return res;
    }
};
