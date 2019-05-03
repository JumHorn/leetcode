#include<vector>
#include<unordered_map>
using namespace std;

/*
if A contains the negetive number

dp[i]=A[0]+A[1]+...A[i]

S[i,j] = dp[j]-dp[i-1]
0<i<=j<n
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
		int res=0,presum=0;
		vector<int> dp(A.size()+1);
		dp[0]=1;
		for(int i=0;i<(int)A.size();i++)
		{
			presum+=A[i];
			if(presum-S>=0)
				res+=dp[presum-S];
			dp[presum]++;
		}
		return res;
    }
};
