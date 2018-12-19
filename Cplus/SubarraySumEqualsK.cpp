#include<vector>
using namespace std;
/*
------------------------->
|    Sum(i,j)=Sum(i-1,j)-A[i];
|
|
|
|
|
|
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		vector<int> dp(nums.size());
		int res=0,sum=0;
		for(int i=0;i<nums.size();i++)
		{
			sum+=nums[i];
			dp[i]=sum;
			if(sum==k)
				res++;
		}
		for(int i=1;i<nums.size();i++)
        {
			for(int j=0;j<i;j++)
			{
				dp[i]=dp[i]-nums[j];
				if(dp[i]==k)
					res++;
			}
        }
		return res;
	}
};



//slide window failed
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//		int start=0,end=0,sum=0,res=0;
// 		while(start<nums.size())
//		{
//			sum+=nums[start];
//			if(sum<k)
//				start++;
//			else if(sum>k)
//			{
//				sum-=nums[end++];
//				sum-=nums[start];
//			}
//			else
//			{
//				start++;
//				res++;
//			}
//		}		
//		return res;
//    }
//};
