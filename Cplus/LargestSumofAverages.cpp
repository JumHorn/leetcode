#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;

/*
k=3 A=9,1,2,3,9

(k,i) 0    1    2    3       4
1     9    5    4    3.75    4.8
2     X    10   10.5 11.0    12.75
3     X    X    12   13.5    20.0

dp[k][i]=max(dp[k-1][i],dp[k-1][j]+(sum[j+1,i]/(i-j));(j<i)
*/

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
		vector<vector<double> > dp(K,vector<double>(A.size()));
		for(int i=0;i<A.size();i++)
			dp[0][i]=accumulate(A.begin(),A.begin()+i+1,0.0)/(i+1);
		for(int k=1;k<K;k++)
			for(int i=k;i<A.size();i++)
			{
				double max=dp[k-1][i];
				for(int j=0;j<i;j++)
				{
					double tmp=accumulate(A.begin()+j+1,A.begin()+i+1,0.0)/(i-j)+dp[k-1][j];
					if(tmp>max)
						max=tmp;
				}
				dp[k][i]=max;
			}
		return dp.back().back();
    }
};
