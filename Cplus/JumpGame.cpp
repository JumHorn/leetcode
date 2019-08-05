#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int n=nums.size(),jump=0,i=0;
		while(i<=jump&&jump<n-1)
		{
			jump=max(jump,i+nums[i]);
			i++;
		}
		return jump>=n-1;
    }
};
