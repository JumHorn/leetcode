#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		nums.push_back(INT_MAX);
	    int res=0;
		for(int i=0;i<nums.size()-1;i++)
		{
			for(int j=i+1;j<nums.size()-1;j++)
			{
				int sum=nums[i]+nums[j],k=j;
				while(nums[++k]<sum)res++;
			}
		}	
		return res;
    }
};
