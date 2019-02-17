#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
		if(nums.size()<3)
			return false;
		int m,n;
		bool flag=false;
        m=n=nums[0];
		for(int i=1;i<(int)nums.size();i++)
		{
			if(nums[i]<m)
			{
				m=n=nums[i];
				flag=false;
			}
			else if(nums[i]>n)
			{
				if(flag)
					return true;
				n=nums[i];
				flag=true;
			}
            else
            {
                if(nums[i]>m)
                    n=nums[i];
            }
		}
		return false;
    }
};
