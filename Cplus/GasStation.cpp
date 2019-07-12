#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N=gas.size();
		vector<vector<int>> dp(N,vector<int>(2,-1));       
		copy(gas.begin(), gas.end(), back_inserter(gas));
		copy(cost.begin(), cost.end(), back_inserter(cost));
		for(int i=0;i<N;i++)
			if((maxReachPoint(gas,cost,dp,i,0))[0]-i>=N)
				return i;
		return -1;
    }

	vector<int> maxReachPoint(vector<int>& gas,vector<int>& cost,vector<vector<int>>& dp,int index,int leftgas)
	{
		if(index>=(int)gas.size())
			return {index-1,0};
		if(dp[index][0]!=-1)
			return dp[index];
		if(gas[index]+leftgas<cost[index])
		{
			if(leftgas==0)
			{
				dp[index][0]=index;
				dp[index][1]=gas[index];
			}
			return {index,gas[index]+leftgas};
		}
		int left=gas[index]+leftgas-cost[index];
		vector<int> far=maxReachPoint(gas,cost,dp,index+1,0);
		vector<int> res=maxReachPoint(gas,cost,dp,far[0],left+dp[far[0]][1]);	
		if(leftgas==0)
			dp[index]=res;
		return res;
	}
};

int main()
{
    Solution sol;
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={3,4,5,1,2};
    sol.canCompleteCircuit(v1,v2);
    return 0;
}