#include<vector>
using namespace std;

class Solution {
	vector<int> tmp;
public:
    int reversePairs(vector<int>& nums) {
		tmp.resize(nums.size());
		return divide(nums,0,nums.size());
    }

	int divide(vector<int>& nums,int start,int end)
	{
		int res=0;
		if(end-start<=1)
			return 0;
		int mid=start+(end-start)/2;
		res=divide(nums,start,mid)+divide(nums,mid,end);
        int j=mid;
		for(int i=start;i<mid;i++)
		{
			while(j<end&&(long)nums[i]-(long)nums[j]>(long)nums[j])
				j++;
			res+=j-mid;
		}
		merge(nums,start,mid,end);
		return res;
	}

	void merge(vector<int>& nums,int start,int mid,int end)
	{
		int s=start,m=mid,d=0,d1=0;
		while(s!=mid&&m!=end)
		    tmp[d++]=(nums[s]>nums[m])?nums[m++]:nums[s++];
		while(s!=mid)
			tmp[d++]=nums[s++];
		while(m!=end)
			tmp[d++]=nums[m++];
		while(start!=end)
			nums[start++]=tmp[d1++];
	}
};
