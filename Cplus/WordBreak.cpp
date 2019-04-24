#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size()+1,false);
		dp[0]=true;
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<(int)wordDict.size();j++)
			{
				if(wordDict[j].size()<=i+1)
				{
					int tmp=i+1-wordDict[j].size();
					if(dp[tmp]&&s.substr(tmp,i+1-tmp)==wordDict[j])
					{
						dp[i+1]=true;
						break;
					}
				}
			}
		}
		return dp.back();
    }
};

int main()
{
	string s1="apple",s2="pen";
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	Solution sol;
	sol.wordBreak("applepenapple",v);
	return 0;
}
