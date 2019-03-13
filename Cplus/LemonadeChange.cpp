#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
		int five=0,ten=0;
		for(int i=0;i<(int)bills.size();i++)
		{
			if(bills[i]==5)
				++five;
			else if(bills[i]==10)
			{
				if(five<=0)
					return false;
				--five;
				++ten;
			}
			else
			{
				if(ten>0)
				{
					--ten;
					if(five<=0)
						return false;
					--five;
				}
				else
				{
					if(five<3)
						return false;
					five-=3;
				}
			}
		}
		return true;
    }
};
