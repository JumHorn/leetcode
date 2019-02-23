#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
		sort(coins.begin(),coins.end());
		return change(coins,0,amount);
    }

	int change(vector<int>& coins,int start,int amount)
	{
		if(amount==0)
			return 1;
		if(amount<0)
			return 0;
		int sum=0;
		for(int i=start;i<(int)coins.size();i++)
			sum+=change(coins,i,amount-coins[i]);		
		return sum;
	}
};
