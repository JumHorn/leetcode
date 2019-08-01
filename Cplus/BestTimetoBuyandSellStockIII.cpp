#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
		int hold1=-prices[0],sold1=0,hold2=-prices[0],sold2=0;
		for(int i=0;i<(int)prices.size();i++)
		{
			hold1=max(-prices[i],hold1);
			sold1=max(hold1+prices[i],sold1);

			hold2=max(sold1-prices[i],hold2);
			sold2=max(hold2+prices[i],sold2);
		}		
		return sold2;
    }
};
