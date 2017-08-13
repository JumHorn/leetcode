#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //时间复杂度O(n^2)
        // vector<int> res;
        // for(int i=1;i<nums.size()+1;i++)
        // {
        //     int j;
        //     for(j=0;j<nums.size();j++)
        //     {
        //         if(nums[j]==i)
        //         {
        //             break;
        //         }
        //     }
        //     if(j==nums.size())
        //     {
        //         res.push_back(i);
        //     }
        // }
        // return res;

        //O(n)解法
        vector<int> res;
        int temp,t;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                continue;
            }
            else
            {
                temp = nums[nums[i]-1];
                nums[nums[i]-1]=0;
                while(temp!=0)
                {
                    t=temp-1;
                    temp=nums[t];
                    nums[t]=0;
                }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

void print(vector<int> vec)
{
    for(vector<int>::iterator iter=vec.begin();iter!=vec.end();iter++)
    {
        cout<<*iter<<",";
    }
    cout<<endl;
}

int main()
{
    int array[] = {4,3,2,7,8,2,3,1};
    vector<int> vec(array,array+8);
    Solution sol;
    print(sol.findDisappearedNumbers(vec));
    return 0;
}