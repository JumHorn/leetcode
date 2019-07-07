#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
		if(p.empty())
			return 0;
		vector<int> res(26);
		int dp;
		char pre=p.back();
		res[p.back()-'a']=1;
		dp=1;
		for(int i=p.size()-2;i>=0;i--)
		{
			if((p[i]!='z'&&pre==p[i]+1)||(p[i]=='z'&&pre=='a'))
                dp++;
            else
			    dp=1;
			res[p[i]-'a']=max(res[p[i]-'a'],dp);
            pre=p[i];
		}
		return accumulate(res.begin(),res.end(),0);
    }
};