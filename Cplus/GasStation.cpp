#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N=gas.size();
		// vector<vector<int>> dp(N);
		for(int i=0;i<N;i++)
			if(maxReachPoint(gas,cost,i))
				return i;
		return -1;
    }

	bool maxReachPoint(vector<int>& gas,vector<int>& cost,int index)
	{
        int N=gas.size(),j=index,left=gas[index]-cost[index];
        while(++j-index<=N)
        {
            if(left<0)
                return false;
            left+=gas[j%N]-cost[j%N];
        }
        return true;
    }
};