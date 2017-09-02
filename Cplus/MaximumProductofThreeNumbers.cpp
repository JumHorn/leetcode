#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//简化solutian思路，未解决全排序浪费时间
class Solution {
public:
    int maximumProduct(vector<int>& nums) {     
		sort(nums.begin(),nums.end());
        if(nums[0]*nums[1]*nums[nums.size()-1]>nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3])
        {
            return nums[0]*nums[1]*nums[nums.size()-1];
        }
        else
        {
            return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]; 
        }	
    }
};

//只需要找出前3和后2，全部排序浪费时间
class Solution1 {
public:
    int maximumProduct(vector<int>& nums) {
		if(nums.size()==3)
		{
			return nums[0]*nums[1]*nums[2];
		}
		sort(nums.begin(),nums.end());
		if(nums[0]>=0||nums[nums.size()-1]<=0||nums[1]>=0)
		{
			return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
		}
		else
		{
			if(nums[0]*nums[1]*nums[nums.size()-1]>nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3])
			{
				return nums[0]*nums[1]*nums[nums.size()-1];
			}
			else
			{
				return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]; 
			}
		}
    }
};

//O(n^3)超时
class Solution0 {
public:
    int maximumProduct(vector<int>& nums) {
		int max=-2147483648;
		int temp;
		for(int i=0;i<nums.size()-2;i++)
			for(int j=i+1;j<nums.size()-1;j++)
				for(int k=j+1;k<nums.size();k++)
				{
					temp=nums[i]*nums[j]*nums[k];
					max=temp>max?temp:max;
				}
		return max;
    }
};

// public int maximumProduct(int[] nums) {
//     int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE, min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
//     for (int n : nums) {
//         if (n > max1) {
//             max3 = max2;
//             max2 = max1;
//             max1 = n;
//         } else if (n > max2) {
//             max3 = max2;
//             max2 = n;
//         } else if (n > max3) {
//             max3 = n;
//         }

//         if (n < min1) {
//             min2 = min1;
//             min1 = n;
//         } else if (n < min2) {
//             min2 = n;
//         }
//     }
//     return Math.max(max1*max2*max3, max1*min1*min2);
// }