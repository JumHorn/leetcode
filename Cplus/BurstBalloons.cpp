#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
		if(nums.empty())
			return 0;
		if(nums.size()==1)
			return nums[0];
		if(nums.size()==2)
			return nums[0]*nums[1]+max(nums[0],nums[1]);		
		int res=0;
		vector<int>::iterator iter=min_element(nums.begin(),nums.end());
		if(iter==nums.begin())
		{
			res+=*(iter+1)**iter;
		}
		else if(iter==nums.end()-1)
		{
			res+=*(iter-1)**iter;
		}
		else
		{
			res+=*(iter-1)*(*iter)**(iter+1);
		}
		nums.erase(iter);
		res+=maxCoins(nums);
		return res;
    }
};
