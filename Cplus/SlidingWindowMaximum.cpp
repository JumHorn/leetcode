#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())
            return vector<int>();
		vector<int> res(nums.size()-k+1);
		res[0]=*max_element(nums.begin(),nums.begin()+k);
		for(int i=1;i<(int)nums.size()-k+1;i++)
		{
			if(nums[i-1]==res[i-1])
				res[i]=*max_element(nums.begin()+i,nums.begin()+i+k);
			else
				res[i]=max(res[i-1],nums[i+k-1]);
		}
		return res;
    }
};
