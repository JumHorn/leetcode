#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		make_heap(nums.begin(),nums.end());
	    for(int i=0;i<k;i++)
			pop_heap(nums.begin(),nums.end()-i);
		return nums[nums.size()-k];	
    }
};
