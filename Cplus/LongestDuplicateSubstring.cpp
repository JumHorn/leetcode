#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string S) {
		int N=S.length(),res=0,start;
		vector<int> dp(N+1);
		for(int i=1;i<=N;i++)
        {
			for(int j=N;j>0;j--)
			{
				if(i==j||S[i-1]!=S[j-1])
					dp[j]=0;
				else
				{
                    dp[j]=dp[j-1]+1;
                    if(dp[j]>res)
                    {
                        res=dp[j];
                        start=i-1;
                    }
				}
			}
        }
		if(res==0)
			return "";
		return S.substr(start-res+1,res);
    }
};