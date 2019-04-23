#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		if(s=="")
			return true;
		for(int i=0;i<(int)wordDict.size();i++)
		{
			if(wordDict[i].size()>s.size())
				continue;
			int j=0;
			while(j<wordDict[i].size()&&wordDict[i][j]==s[j])
				j++;
			if(j!=wordDict[i].size())
				continue;
			if(wordBreak(s.substr(j),wordDict))
				return true;
		}		
		return false;
    }
};
