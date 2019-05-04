#include<climits>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
		vector<vector<int> > dp(key.length(),vector<int>(ring.length()));
		//dp first row
		int n=ring.length();
		for(int i=0;i<n;i++)
        {
            dp[0][i]=INT_MAX;
			if(ring[i]==key[0])
				dp[0][i]=min(i,n-i);
        }

		for(int i=1;i<(int)key.length();i++)
			for(int j=0;j<(int)ring.length();j++)
			{
				dp[i][j]=INT_MAX;
				if(ring[j]==key[i])
				{
					for(int k=0;k<(int)ring.length();k++)
					{
						if(dp[i-1][k]!=INT_MAX)
						{
							int step=abs(j-k);
							dp[i][j]=min(dp[i][j],dp[i-1][k]+min(step,n-step));
						}
					}
				}
			}

		int m=key.length(),res=INT_MAX;
		for(int i=0;i<(int)ring.length();i++)
			res=min(res,dp[m-1][i]);

		return res+key.length();
    }
};
