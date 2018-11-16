#include<vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
		vector<int> hash(10001,0);
		for(int i=0;i<nums.size();i++)
			hash[nums[i]]++;
        int good=hash.size()-1;
        while(hash[good]==0)good--;
		for(int i=1;i<=good;i++)
			hash[i]*=i;
		hash[2]=max(hash[1],hash[2]);
		for(int i=3;i<=good;i++)
			hash[i]=max(hash[i-1],hash[i-2]+hash[i]);
		return hash[good];
    }
};
