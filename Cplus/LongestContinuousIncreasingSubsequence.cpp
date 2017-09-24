#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
		if(nums.size()==0)
		{
			return 0;
		}
		int result = 1, total,subscript=0,i=0;
		while(subscript<nums.size())
		{
			total=1;
			i=subscript;
			for(i=i+1;i<nums.size();i++)
			{
				if(nums[i]>nums[i-1])
				{
					total++;
				}
				else
				{
					break;
				}
            }
            subscript = i;
			if(total>result)
			{
				result = total;
            }
            //原先以为加上这段会时间更短，可是testcase里面没有这种情况
            //反而因为多加判断变慢了
            // if(nums.size()-subscript<=total)
            // {
            //     break;
            // }
		}
		return result;
    }
};
