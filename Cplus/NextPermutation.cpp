#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int i=nums.size(); 
		while(--i>0)
		{
			if(nums[i]>nums[i-1])
			{
				int j=nums.size()-1;
				while(nums[j]<=nums[i-1])
					j--;
				swap(nums[i-1],nums[j]);
				reverse(nums.begin()+i,nums.end());
				return;
			}
		}
		reverse(nums.begin(),nums.end());
    }
};
