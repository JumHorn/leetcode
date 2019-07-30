#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int count1=0,count2=0,value1=0,value2=1;
		for(int i=0;i<(int)nums.size();i++)     
		{
			if(nums[i]==value1)
				++count1;
			else if(nums[i]==value2)
				++count2;
			else if(count1==0)
			{
				value1=nums[i];
				++count1;
			}
			else if(count2==0)
			{
				++count2;
				value2=nums[i];
			}
			else
			{
				--count1;
				--count2;
			}
		}
		vector<int> res;

		count1=0;
		for(int i=0;i<(int)nums.size();i++)
			if(value1==nums[i])
				++count1;
		if(count1>(int)nums.size()/3)
			res.push_back(value1);

		count2=0;
		for(int i=0;i<(int)nums.size();i++)
			if(value2==nums[i])
				++count2;
		if(count2>(int)nums.size()/3)
			res.push_back(value2);
		return res;
    }
};
