#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
		long long all=accumulate(A.begin(),A.end(),(long long)0);
		long long res=INT_MIN,n=A.size(),tmp=0;
		for(int i=0;i<n;i++)
			tmp+=i*A[i];
		res=tmp;
		for(int i=1;i<n;i++)
		{
			tmp=tmp+all-n*A[n-i];
			res=max(res,tmp);
		}
		return res;
    }
};
