#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //多次对iter!=nums.end()判断，效率低下
        // int sum=0;
        // int temp=0;
        // vector<int>::iterator iter=nums.begin();
        // while(iter!=nums.end())
        // {
        //     while(iter!=nums.end()&&*iter==0)
        //     {
        //         iter++;
        //     }
        //     temp=0;
        //     while(iter!=nums.end()&&*iter==1)
        //     {
        //         iter++;
        //         temp++;
        //     }
        //     if(temp>sum)sum=temp;
        // }
        // return sum;

        int sum=0;
        int temp=0;
        for(vector<int>::iterator iter=nums.begin();iter!=nums.end();iter++)
        {
            if(*iter==0)
            {
                if(temp>sum)sum=temp;
                temp=0;
                continue;  
            }
            else
            {
                temp++;
            }
        }
        return sum>temp?sum:temp;
    }
};

int main()
{}