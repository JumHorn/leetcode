#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		if(s.empty())
			return 0;
		if(s.length()==1)
			return s.front()=='0'?0:1;
		if(s.front()=='0')
			return 0;
		vector<int> dp(s.length());        
		dp[0]=dp[1]=1;
		if(s[0]=='2'&&s[1]<='6'&&s[1]!='0')
			dp[1]=2;
		else if(s[0]=='1'&&s[1]<='9'&&s[1]!='0')
			dp[1]=2;
		else if(s[0]>'2'&&s[1]=='0')
			dp[1]=0;
		for(int i=2;i<(int)s.length();i++)
		{
			if(s[i]!='0')
				dp[i]+=dp[i-1];
			if(s[i-1]!='0'&&s[i-1]=='1'&&s[i]<='9')
				dp[i]+=dp[i-2];
			else if(s[i-1]!='0'&&s[i-1]=='2'&&s[i]<='6')
				dp[i]+=dp[i-2];
		}
		return dp.back();
    }
};
