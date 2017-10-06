#include<iostream>
#include<vector>
#include<limits>
using namespace std;

//greater solution
// class Solution {
// public:
//     int maxSubArray(vector<int> nums) {
//         int ans=nums[0],i,j,sum=0;
//         for(i=0;i<nums.size();i++){
//             sum+=nums[i];
//             ans=max(sum,ans);
//             sum=max(sum,0);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int result=nums[0],i,j,sum=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            result=sum>result?sum:result;
            sum=sum>0?sum:0;
        }
        return result;
    }
};

//time limit exceeded
// class Solution0 {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int result=INT_MIN,numsum;
//         for(int i=1;i<nums.size()+1;i++)
//         {
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(i+j>nums.size())
//                 {
//                     break;
//                 }
//                 numsum=0;
//                 for(int k=j;k<j+i;k++)
//                 {
//                     numsum+=nums[k];
//                 }
//                 if(numsum>result)
//                 {
//                     result=numsum;
//                 }
//             }
//         }
//         return result;
//     }
// };