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
        for(int i=start,j=mid;i<mid;i++)
        {
            while(j!=end&&pairs[i].first>pairs[j].first)
                j++;
            res[pairs[i].second]+=j-mid;
        }
		merge(pairs,start,mid,end);
	}

	void merge(vector<pair<int,int> >& pairs,int start,int mid,int end)
	{
		int s=start,m=mid,d=0,d1=0;
		while(s!=mid&&m!=end)
		    tmp[d++]=(pairs[s].first>pairs[m].first)?pairs[m++]:pairs[s++];
		while(s!=mid)
			tmp[d++]=pairs[s++];
		while(m!=end)
			tmp[d++]=pairs[m++];
		while(start!=end)
			pairs[start++]=tmp[d1++];
	}
};
