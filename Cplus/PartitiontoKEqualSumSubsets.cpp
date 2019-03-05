#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
		if(sum%k!=0)
			return false;
		sum/=k;
		sort(nums.begin(),nums.end());
		if(nums.back()>sum)
			return false;
		return true;
    }
};
