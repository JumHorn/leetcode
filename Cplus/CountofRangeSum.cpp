#include<vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		vector<long> sums(nums.size()+1);
		for(int i=0;i<(int)nums.size();i++)
			sums[i+1]+=sums[i]+nums[i];
		int res=0;
		for(int j=1;j<(int)sums.size();j++)
			for(int i=0;i<j;i++)
				if(sums[j]-sums[i]>=lower&&sums[j]-sums[i]<=upper)
					res++;
		return res;
    }
};
