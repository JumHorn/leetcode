#include<vector>
#include<unordered_map>
using namespace std;

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
