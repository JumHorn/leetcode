#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
		int i=0,j=0,res=0,tmp=0;
		for(j=0;j<(int)nums.size();)
		{
			for(int k=i;k<=j;k++)
				tmp=max(tmp,k+nums[k]);
			if(tmp>=(int)nums.size()-1)
				return res+1;
			i=j+1;
			j=tmp;
			res++;
		}
		return res;
    }
};
