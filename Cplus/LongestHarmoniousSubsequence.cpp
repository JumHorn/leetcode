#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int result = 1, total,subscript=0,i=0,temp,exact1=0;
		while(subscript<nums.size())
		{
			total=1;
            i=subscript;
            temp = subscript;
            exact1 = 0;
			for(i=i+1;i<nums.size();i++)
			{
				if(nums[i]-nums[subscript]==1)
				{
                    exact1 = 1;
                    if(temp==subscript)
                        temp = i;
					total++;
				}
				else if(nums[i]-nums[subscript]==0)
				{
					total++;
                }
                else
                {
                    break;
                }
            }
            subscript = (temp!=subscript&&temp<i)?temp:i;
			if(exact1==1&&total>result)
			{
				result = total;
            }
            // if(nums.size()-subscript<=total)
            // {
            //     break;
            // }
		}
		return result;
    }
};