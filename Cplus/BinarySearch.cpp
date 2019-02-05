#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		if(nums.empty())
			return -1;
		return search(nums,target,0,nums.size()-1);
    }

    int search(vector<int>& nums, int target,int left,int right) {
		int mid=(left+right)/2;
		if(nums[mid]==target)
			return mid;
		if(right<=left)
			return -1;
		if(nums[mid]<target)
			return search(nums,target,mid+1,right);
		return search(nums,target,left,mid);
    }
};
