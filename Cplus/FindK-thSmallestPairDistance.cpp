#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> tmp(nums.size());
		priority_queue<int> q;
		divideAndMerge(nums,0,nums.size(),tmp,k,q);
		return q.top();
    }

	int divideAndMerge(vector<int>& nums,int start,int end,vector<int>& tmp,int k,priority_queue<int>& q)
	{
		if(end-start<=1)
			return 0;
		int mid=(end-start)/2+start;
		int res=divideAndMerge(nums,start,mid,tmp,k,q)+divideAndMerge(nums,mid,end,tmp,k,q);
		//todo
		int i=start,j=mid;	
		for(;i<mid;i++)
		{
			while(j<end&&nums[i]>nums[j])
				j++;
			int tmp=j-1;
			while(tmp>=mid)
			{
				int d=nums[i]-nums[tmp];
				if((int)q.size()<k)
					q.push(d);
				else if(d<q.top())
				{
					q.pop();
					q.push(d);
				}
				else
					break;
				tmp--;
			}
			tmp=j;
			while(tmp<end)
			{
				int d=nums[tmp]-nums[i];
				if((int)q.size()<k)
					q.push(d);
				else if(d<q.top())
				{
					q.pop();
					q.push(d);
				}
				else
					break;
				tmp++;
			}
		}

		merge(nums.begin()+start,nums.begin()+mid,nums.begin()+mid,nums.begin()+end,tmp.begin());
		copy(tmp.begin(),tmp.begin()+end-start,nums.begin()+start);
		return res;
	}
};
