#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
		vector<int> dp(A[0].size(),1);    
		for(int i=1;i<(int)dp.size();i++)
		{
			int j,k;
            for(k=0;k<i;k++)
			{
                for(j=0;j<(int)A.size();j++)
                    if(A[j][i]<A[j][k])
                        break;
            	if(j==(int)A.size())
				    dp[i]=max(dp[i],dp[k]+1);
			}
		}
		return A[0].size()-*max_element(dp.begin(),dp.end());
    }
};