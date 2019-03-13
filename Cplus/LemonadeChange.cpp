#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> money;
		for(int i=0;i<(int)bills.size();i++)
		{
			if(bills[i]==5)
				++money[5];
			else if(bills[i]==10)
			{
				if(money[5]<=0)
					return false;
				--money[5];
				++money[10];
			}
			else
			{
				++money[20];
				if(money[10]>0)
				{
					--money[10];
					if(money[5]<=0)
						return false;
					--money[5];
				}
				else
				{
					if(money[5]<3)
						return false;
					money[5]-=3;
				}
			}
		}
		return true;
    }
};
