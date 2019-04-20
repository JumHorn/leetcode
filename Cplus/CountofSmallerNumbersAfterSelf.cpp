#include<vector>
using namespace std;

class Solution {
    vector<pair<int,int> > tmp;
public:
    vector<int> countSmaller(vector<int>& nums) {
		vector<int> res(nums.size());
        tmp.resize(nums.size());
		vector<pair<int,int> > pairs(nums.size());
		for(int i=0;i<(int)nums.size();i++)
		{
			pairs[i].first=nums[i];
			pairs[i].second=i;
		}
		mergeSort(res,pairs,0,nums.size());
		return res;
    }

	void mergeSort(vector<int>& res,vector<pair<int,int> >& pairs,int start,int end)
	{
		if(end-start<=1)
			return;
		int mid=(end-start)/2+start;
		mergeSort(res,pairs,start,mid);
		mergeSort(res,pairs,mid,end);
		merge(res,pairs,start,mid,end);
	}

	void merge(vector<int>& res,vector<pair<int,int> >& pairs,int start,int mid,int end)
	{
		int s=start,m=mid,d=0,d1=0;
		while(s!=mid&&m!=end)
		{
			if(pairs[s].first>pairs[m].first)
			{
				for(int i=s;i!=mid;i++)
					res[pairs[i].second]++;
				tmp[d++]=pairs[m++];
			}
			else
			{
				tmp[d++]=pairs[s++];
			}
		}
		while(s!=mid)
			tmp[d++]=pairs[s++];
		while(m!=end)
			tmp[d++]=pairs[m++];
		while(start!=end)
			pairs[start++]=tmp[d1++];
	}
};
