#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Comp
{
public:
    bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first<rhs.first;
        return lhs.second<rhs.second;
    }
};

class Solution {
    set<pair<int,int>,Comp> s;
public:
    int oddEvenJumps(vector<int>& A) {
        s.clear();
		vector<vector<int>> dp(A.size(),vector<int>(2));        
		dp.back()[0]=1;
		dp.back()[1]=1;
        s.insert({A.back(),A.size()-1});
		for(int i=A.size()-2;i>=0;i--)
        {
            dp[i][0]=jumps(A,i,0,dp);
            dp[i][1]=jumps(A,i,1,dp);
            s.insert({A[i],i});
        }
        int res=0;
		for(int i=0;i<(int)dp.size();i++)
            if(dp[i][1]==1)
                res++;
        return res;
    }

	int jumps(vector<int>& A,int i,int oddeven,vector<vector<int>>& dp)
	{
		if(i==-1)
			return -1;
        if(dp[i][oddeven]!=0)
            return dp[i][oddeven];
        int res;
		if(oddeven==0)//even
			res=jumps(A,getEven(A,i),(oddeven+1)&1,dp);
		else
			res=jumps(A,getOdd(A,i),(oddeven+1)&1,dp);
		return res;
	}

	int getOdd(vector<int>& A,int i)
	{
        auto iter=s.lower_bound({A[i],i});
        if(iter==s.end())
            return -1;
		return iter->second;
	}

	int getEven(vector<int>& A,int i)
	{
        auto iter=s.lower_bound({A[i],i});
        if(iter==s.end())
            --iter;
        while(iter!=s.begin())
        {
            if(iter->first<=A[i])
            {
                int val=iter->first;
                --iter;
                while(iter!=s.begin()&&val==iter->first)
                    --iter;
                if(iter->first!=val)
                    return (++iter)->second;
                return iter->second;
            }
            --iter;
        }
        if(iter->first<=A[i])
            return iter->second;
        return -1;
	}
};