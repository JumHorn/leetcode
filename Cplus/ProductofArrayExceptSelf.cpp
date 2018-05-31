#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		long long allmultiply = 1;
		int zero = 0,index=0;
		vector<int> result(nums.size(),0);
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]==0)
			{
				index = i;
				zero++;
				if(zero==2)
				{
					return result;
				}
				continue;
			}
			
			allmultiply*=nums[i];
		}
		if(zero==1)
		{
			result[index] = allmultiply;
			return result;
		}
		
		for(int i=0;i<nums.size();i++)
		{
			result[i] = division(allmultiply,nums[i]);
		}
		return result;
	}

	int division(long dividend, long divisor)
	{
		long quotient=0,temp=1;
		int symbol=1,i=0;
		long d1=dividend,d2=divisor;
		if(dividend<0)
		{
			d1=-d1;
			symbol *= -1;
		}
		if(divisor<0)
		{
			d2=-d2;
			symbol *= -1;
		}

		while(true)
		{
			if(d1-d2*(temp<<i)==0)
			{
				quotient += temp<<i;
				break;
			}
			else if(d1-d2*(temp<<i)<0)
			{
				quotient += temp<<(i-1);
				d1 -= d2*(temp<<(i-1));
				i=0;
			}
			else
			{
				i++;
			}
		}
		return symbol*quotient;
	}
};
