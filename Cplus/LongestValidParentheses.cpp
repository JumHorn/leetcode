#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
		vector<int> dp(s.length());        
		for(int i=1;i<(int)s.length();i++)
		{
			if(s[i]==')')
			{
				int j=i-1;
				while(j>=0&&dp[j]!=0)
					j-=dp[j];
				if(j>=0&&s[j]=='(')
					dp[i]=i-j+1+(j>=1?dp[j-1]:0);
			}
		}
        return *max_element(dp.begin(),dp.end());
    }
};
