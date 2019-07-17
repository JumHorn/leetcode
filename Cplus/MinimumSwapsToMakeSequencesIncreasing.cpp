#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
		vector<vector<int>> dp(A.size(),vector<int>(2,-1));
		int res=minSwap(A,B,1,dp);
		if(A[0]!=B[0])
		{
			swap(A[0],B[0]);
			res=min(res,minSwap(A,B,1,dp)+1);	
		}
		return res;        
    }

	int minSwap(vector<int>& A,vector<int>& B,int index,vector<vector<int>>& dp)
	{
		if(index>=(int)A.size())
			return 0;
		int res=INT_MAX;
		if(A[index]==B[index])
        {
            if(dp[index][0]!=-1)
                return dp[index][0];
			res=minSwap(A,B,index+1,dp);
            dp[index][0]=res;
            return res;
        }
		bool flag=true;
		if(A[index]>A[index-1]&&B[index]>B[index-1])
		{
			flag=false;
            if(dp[index][0]!=-1)
                res=dp[index][0];
            else
            {
			    res=min(res,minSwap(A,B,index+1,dp));
                dp[index][0]=res;
            }
		}
		if(A[index]>B[index-1]&&B[index]>A[index-1])
		{
			flag=false;
			swap(A[index],B[index]);
            if(dp[index][1]!=-1)
                res=dp[index][1];
            else
            {
			    res=min(res,minSwap(A,B,index+1,dp)+1);
                dp[index][1]=res;
            }
            swap(A[index],B[index]);
		}
		if(flag)
			res=10000;
		return res;
	}
};