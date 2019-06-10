#include<vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
		long m=1;
        int res=0;
		for(int i=0;i<(int)nums.size();i++)
		{
			if(nums[i]>m)
			{
				res++;
				m+=m;
                i--;
			}
			else
				m+=nums[i];
			if(m-1>=n)
				return res;
		}
		if(m==1)
		{
            res=1;
            m=2;
		}
		while(m-1<n)
		{
			res++;
			m+=m;
		}
		return res;
    }
};
