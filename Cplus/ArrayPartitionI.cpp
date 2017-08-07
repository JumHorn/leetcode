#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2)
        {
            sum+=nums[i];
        }
        return sum;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(3);
    Solution sol;
    cout<<sol.arrayPairSum(vec)<<endl;
    return 0;
}