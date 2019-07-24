#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
		int N=A.size(),res=INT_MIN,minimum=0;
        bool flag=true;
		vector<int> sum(2*N+1);
		for(int i=1;i<(int)sum.size();i++)
		{
			if(i<=N)
            {
				sum[i]=sum[i-1]+A[i-1];
                if(A[i-1]<0)
                    flag=false;
            }
			else
				sum[i]=sum[i-1]+A[i-N-1];
		}
        if(flag)
            return accumulate(A.begin(),A.end(),0);
		for(int i=1;i<(int)sum.size();i++)
		{
			res=max(res,sum[i]-sum[minimum]);
			if(sum[i]<=sum[minimum])
				minimum=i;
			if(i>=N&&i-N==minimum)
				minimum=distance(sum.begin(),min_element(sum.begin()+i-N+1,sum.begin()+i+1));
		}
		return res;
    }
};
