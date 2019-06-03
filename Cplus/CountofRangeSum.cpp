#include<vector>
using namespace std;

class Solution {
	vector<int> tmp;
	int low;
	int up;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		vector<long> sums(nums.size()+1);
		for(int i=0;i<(int)nums.size();i++)
			sums[i+1]+=sums[i]+nums[i];
		tmp.resize(sums.size());
		low=lower;
		up=upper;
		return divide(sums,0,sums.size());
    }

	int divide(vector<long>& sums,int start,int end)
	{
		int res=0;
		if(end-start<=1)
			return 0;
		int mid=start+(end-start)/2;
		res=divide(sums,start,mid)+divide(sums,mid,end);
        int j=mid,k=mid;
		for(int i=start;i<mid;i++)
		{
			while(j<end&&sums[j]-sums[i]<low)
				j++;
			while(k<end&&sums[k]-sums[i]<=up)
				k++;
			res+=k-j;
		}
		merge(sums,start,mid,end);
		return res;
	}

	void merge(vector<long>& sums,int start,int mid,int end)
	{
		int s=start,m=mid,d=0,d1=0;
		while(s!=mid&&m!=end)
		    tmp[d++]=(sums[s]>sums[m])?sums[m++]:sums[s++];
		while(s!=mid)
			tmp[d++]=sums[s++];
		while(m!=end)
			tmp[d++]=sums[m++];
		while(start!=end)
			sums[start++]=tmp[d1++];
	}
};
