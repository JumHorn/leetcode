#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int *p = new int[nums.size()+1];
		memset(p,0,sizeof(int)*(nums.size()+1));
		for(vector<int>::iterator iter=nums.begin();iter!=nums.end();iter++)
		{
			*(p+*iter)=-1;
		}
		for(int i=0;i<=nums.size();i++)
		{
			if(p[i]==0)
			{
				return i;
			}
		}
		return 0;
    }
};
