#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size();
	    vector<int> M(len,0);
		for(int i=1;i<len;i++)
		{
			int max=M[i-1];
			for(int j=0;j<i;j++)
			{
				if(prices[i]-prices[j]+M[j]-fee>max)
				{
					max=prices[i]-prices[j]+M[j]-fee;
				}
			}
			M[i]=max;
		}
		return M[len-1];
    }
};
