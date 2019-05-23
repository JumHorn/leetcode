#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> res;
		wordBreak(s,0,res,"",wordDict);
		return res;
    }

	void wordBreak(const string& s,int index,vector<string>& res,string tmp,vector<string>& wordDict)
	{
		if(index>(int)s.size()-1)
		{
			res.push_back(tmp);
			return;
		}
		for(int i=0;i<(int)wordDict.size();i++)
		{
			string tmp1=tmp;
			if(s.substr(index,wordDict[i].size())==wordDict[i])
			{
				if(tmp1=="")
					tmp1=wordDict[i];
				else
					tmp1+=" "+wordDict[i];
				wordBreak(s,index+wordDict[i].size(),res,tmp1,wordDict);
			}
		}
	}
};
