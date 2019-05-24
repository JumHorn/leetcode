#include<vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=1;i<(int)nums.size();i++)
            res=max(res,nums[i]-nums[i-1]);
        return res;
    }
};
