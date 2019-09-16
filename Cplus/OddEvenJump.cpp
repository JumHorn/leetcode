#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
		vector<vector<int>> dp(A.size(),vector<int>(2));        
		dp.back()[0]=1;
		dp.back()[1]=1;
		for(int i=(int)A.size()-1;i>=0;i--)
			if(dp[i][1]==0)
				dp[i][1]=jumps(A,i,1,dp);
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
		if(oddeven==0)//even
			dp[i][oddeven]=jumps(A,getEven(A,i),(oddeven+1)&1,dp);
		else
			dp[i][oddeven]=jumps(A,getOdd(A,i),(oddeven+1)&1,dp);
		return dp[i][oddeven];
	}

	int getOdd(vector<int>& A,int i)
	{
		int res=-1,val=A[i];
		for(int j=i+1;j<(int)A.size();j++)
		{
			if(A[j]>=val)
			{
                if(res==-1)
				    res=j;
                else if(A[j]<A[res])
                    res=j;
			}
		}
		return res;
	}

	int getEven(vector<int>& A,int i)
	{
		int res=-1,val=A[i];
		for(int j=i+1;j<(int)A.size();j++)
		{
			if(A[j]<=val)
            {
                if(res==-1)
				    res=j;
                else if(A[j]>A[res])
                    res=j;
            }
		}
		return res;
	}
};