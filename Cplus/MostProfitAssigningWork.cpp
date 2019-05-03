#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		sort(worker.begin(),worker.end());       
		for(int i=0;i<(int)difficulty.size();i++)
		{
			for(int j=(int)difficulty.size()-1;j>i;j--)
			{
				if(difficulty[j-1]>difficulty[j])
				{
					swap(difficulty[j-1],difficulty[j]);
					swap(profit[j-1],profit[j]);
				}
			}
		}
		for(int i=1;i<(int)profit.size();i++)
			profit[i]=max(profit[i],profit[i-1]);

		int res=0,d=0,i=0;
		//worker who's profit is 0
		while(i<(int)worker.size()&&difficulty[0]>worker[i])
			i++;
		//worker who's profit >0
		for(;i<(int)worker.size();i++)
		{
			while(d<(int)difficulty.size()&&worker[i]>=difficulty[d])
				d++;
			res+=profit[d-1];
		}
		return res;
    }
};
