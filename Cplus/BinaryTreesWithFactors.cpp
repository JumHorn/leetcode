#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
	const static int MOD=1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        set<int> s(A.begin(),A.end());
		unordered_map<int,long> dp;
		for(set<int>::iterator it0=s.begin();it0!=s.end();++it0)
		{
			for(set<int>::iterator it1=s.begin();it1!=it0;++it1)
			{
                if((*it0)%(*it1)==0)
                {
                    int tmp=(*it0)/(*it1);
                    if(s.find(tmp)!=s.end())
                    {
                        // if(*it1==tmp)
                        //     dp[*it0]=(dp[*it0]+dp[*it1]*dp[tmp])%MOD;
                        // else
                        dp[*it0]=(dp[*it0]+dp[*it1]*dp[tmp])%MOD;
                    }
                }
			}
			++dp[*it0];
		}
		int res=0;
		for(unordered_map<int,long>::iterator it=dp.begin();it!=dp.end();++it)
			res=(res+it->second)%MOD;
		return res;
    }
};