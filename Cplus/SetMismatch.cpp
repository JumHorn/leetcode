#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==0)
            {
                result[0]=nums[i];
            }
            if(nums[i]-nums[i-1]==2)
            {
                result[1]=nums[i]-1;
            }
        }
        if(nums[0]>1)
        {
            result[1]=1;
        }
        if(result[1]==0)
        {
            result[1]=nums.size();
        }
        return result;
    }
};


// time limit exceeded
// class Solution0 {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         vector<int> result(2);
//         int temp,flag=0,flag1=1,i;
//         for(i=0;i<nums.size();i++)
//         {
//             for(int j=nums.size()-1;j>i;j--)
//             {
//                 if(nums[j-1]>nums[j])
//                 {
//                     temp=nums[j];
//                     nums[j]=nums[j-1];
//                     nums[j-1]=temp;
//                 }
//                 if(!flag&&nums[j-1]==nums[j])
//                 {
//                     result[0]=nums[j];
//                     flag=1;
//                 }
//             }
//             if(flag1&&i>0&&nums[i]-nums[i-1]>1)
//             {
//                 result[1]=nums[i]-1;
//                 flag1=0;
//             }
//             if(flag1&&nums[i]-i>1)
//             {
//                 result[1]=i+1;
//                 flag1=0;
//             }
//             if(flag1==0&&flag==1)
//             {
//                 break;
//             }
//         }
//         if(i==nums.size())
//         {
//             result[1]=i;
//         }
//         return result;
//     }
// };


//using XOR
// public class Solution {
//     public int[] findErrorNums(int[] nums) {
//         int xor = 0, xor0 = 0, xor1 = 0;
//         for (int n: nums)
//             xor ^= n;
//         for (int i = 1; i <= nums.length; i++)
//             xor ^= i;
//         int rightmostbit = xor & ~(xor - 1);
//         for (int n: nums) {
//             if ((n & rightmostbit) != 0)
//                 xor1 ^= n;
//             else
//                 xor0 ^= n;
//         }
//         for (int i = 1; i <= nums.length; i++) {
//             if ((i & rightmostbit) != 0)
//                 xor1 ^= i;
//             else
//                 xor0 ^= i;
//         }
//         for (int i = 0; i < nums.length; i++) {
//             if (nums[i] == xor0)
//                 return new int[]{xor0, xor1};
//         }
//         return new int[]{xor1, xor0};
//     }
// }