#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > result;
    vector<vector<int> > permute(vector<int>& nums) {
		vector<vector<int> > res;
		this->result=res;		
		permutation(nums,0,nums.size());
		return result;
    }

	void permutation(vector<int>& nums,int l,int r)
	{
		if(l==r)
		{
			result.push_back(nums);
		}
		else
		{
			for(int i=l;i<r;i++)
			{
				swap(nums[i],nums[l]);
				permutation(nums,l+1,r);
				swap(nums[i],nums[l]);
			}
		}
	}
};
