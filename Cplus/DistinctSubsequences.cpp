#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
		vector<vector<int> > dp(s.size()+1,vector<int>(t.size()+1,-1));
		return numDistinct(s,0,t,0,dp);
    }

	int numDistinct(const string& s,int i,const string& t,int j,vector<vector<int> >& dp)
	{
		if(j>=(int)t.size())
			return 1;
		if(i<(int)s.size()&&dp[i][j]!=-1)
			return dp[i][j];
		int res=0;
		for(int k=i;k<(int)s.size();k++)
		{
			if(s[k]==t[j])
			{
				int tmp=numDistinct(s,k+1,t,j+1,dp);
				dp[k+1][j+1]=tmp;
				res+=tmp;
			}
		}
		return res;
	}
};
