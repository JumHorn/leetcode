#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
		int targetchar=0;
        map<char,int> t;
		vector<map<char,int> > s(stickers.size());
		for(int i=0;i<(int)target.size();i++)
		{
			targetchar++;
			++t[target[i]];
		}
		for(int i=0;i<(int)stickers.size();i++)
			for(int j=0;j<(int)stickers[i].size();j++)
				++s[i][stickers[i][j]];
		map<map<char,int>,int> dp;
		return minStickers(s,t,targetchar,dp);
    }

	int minStickers(vector<map<char,int> >& stickers, map<char,int>& target,int targetchar,map<map<char,int>,int>& dp)
	{
		if(dp.find(target)!=dp.end())
			return dp[target];
		if(targetchar==0)
			return 0;
		int res=INT_MAX,tmpchar;
		map<char,int> tmpmap,minmap;
		for(int i=0;i<(int)stickers.size();i++)
		{
			tmpchar=targetchar;
			for(map<char,int>::iterator iter=target.begin();iter!=target.end();++iter)
			{
				if(iter->second>=stickers[i][iter->first])
				{
					tmpmap[iter->first]=iter->second-stickers[i][iter->first];
					tmpchar-=stickers[i][iter->first];
				}
				else
				{
					tmpmap[iter->first]=0;
					tmpchar-=iter->second;
				}
			}
			if(tmpchar<targetchar)
			{
				int tmp=minStickers(stickers,tmpmap,tmpchar,dp);
				if(tmp!=-1)
					res=min(res,1+tmp);
			}
		}
		if(targetchar==tmpchar)
			return -1;
		dp[target]=res;
		return res;
	}
};