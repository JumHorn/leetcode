#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
		int res=INT_MAX;
		splitArray(nums,m,0,INT_MIN,res);
		return res;
	}

    void splitArray(vector<int>& nums, int m,int start,int sum,int& res) {
		int tmp=0;
		if(m==1)
		{
			for(int i=start;i<(int)nums.size();i++)
				tmp+=nums[i];
			res=min(res,max(sum,tmp));
			return;
		}
    	for(int i=start;i<=(int)nums.size()-m;i++)
		{
			tmp+=nums[i];
			int n=max(tmp,sum);
			if(n>=res)
				return;
			splitArray(nums,m-1,i+1,n,res);
		}	
    }
};
