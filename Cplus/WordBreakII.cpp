#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
		if(!canBreak(s,wordDict))
			return vector<string>();
		vector<unordered_set<string> > dp(s.length()+1,unordered_set<string>());
		for(int i=0;i<(int)s.length();i++)
			wordBreak(s,i,dp,wordDict);
		return vector<string>(dp.back().begin(),dp.back().end());
    }

	bool canBreak(const string& s,vector<string>& wordDict)
	{
		vector<bool> dp(s.length()+1);
		unordered_set<string> dict(wordDict.begin(),wordDict.end());
		dp[0]=true;
		for(int i=0;i<(int)s.length();i++)
		{
			for(int j=i;j>=0;j--)
			{
				if(dict.find(s.substr(j,i-j+1))!=dict.end())
					dp[i+1]=dp[i+1]||dp[j];
				if(dp[i+1])
					break;
			}
		}
		return dp.back();
	}

	void wordBreak(const string& s,int index,vector<unordered_set<string> >& dp,vector<string>& wordDict)
	{
		for(int i=0;i<(int)wordDict.size();i++)
		{
			if(index+1<(int)wordDict[i].length())
				continue;
			else if(index+1==(int)wordDict[i].length())
			{
				if(s.substr(0,index+1)==wordDict[i])
					dp[index+1].insert(wordDict[i]);
			}
			else if(s.substr(index-wordDict[i].size()+1,wordDict[i].size())==wordDict[i])
			{
				int tmp=index-wordDict[i].size()+1;
				for(unordered_set<string>::iterator iter=dp[tmp].begin();iter!=dp[tmp].end();++iter)
					dp[index+1].insert(*iter+" "+wordDict[i]);
			}
		}
	}
};
