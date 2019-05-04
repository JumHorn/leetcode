#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int res=0,product=1,i=-1,j=0;
		while(++i<(int)nums.size())
		{
			product*=nums[i];
            while(j<=i&&product>=k)
                product/=nums[j++];
            res+=i-j+1;
		}
		return res;
    }
};
