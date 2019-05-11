#include<string>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
	static const int mod=1e9+7;
public:
    int distinctSubseqII(string S) {
		vector<int> dp(S.length());
		dp[0]=1;
		for(int i=1;i<(int)S.length();i++)
		{
			dp[i]=(dp[i-1]*2+1)%mod;
			for(int j=i-1;j>=0;j--)
                if(S[j]==S[i])
                {
				    dp[i]=(mod+dp[i]-dp[j])%mod;
                    break;
                }
		}
		return dp.back();
    }
};
