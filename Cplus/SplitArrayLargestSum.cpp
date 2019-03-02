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
			tmp=0;
			for(int j=start;j<=i;j++)
				tmp+=nums[j];
			splitArray(nums,m-1,i+1,max(tmp,sum),res);
		}	
    }
};
