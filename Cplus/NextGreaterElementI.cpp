#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        //构造map
        map<int,int> mapindex;
        for(int i=0;i<nums.size();i++)
        {
            mapindex[nums[i]]=i;
        }

        for(vector<int>::iterator iter=findNums.begin();iter!=findNums.end();iter++)
        {
            // if(mapindex[*iter]+1==nums.size()||*iter>=nums[mapindex[*iter]+1])
            // {
            //     *iter=-1;
            //     continue;
            // }
            // *iter=nums[mapindex[*iter]+1];
            int i;
            for(i=mapindex[*iter]+1;i<nums.size();i++)
            {
                if(nums[i]>*iter)
                {
                    *iter=nums[i];
                    break;
                }
            }
            if(i==nums.size())
            {
                *iter=-1;
            }
        }
        return findNums;
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
    int nums1[] = {4,1,2}; 
    int nums2[] = {1,3,4,2};
    vector<int> vec1,vec2;
    vec1.insert(vec1.begin(),nums1,nums1+3);
    vec2.insert(vec2.begin(),nums2,nums2+4);
    print(vec2);

    Solution sol;
    print(sol.nextGreaterElement(vec1,vec2));
    return 0;
}