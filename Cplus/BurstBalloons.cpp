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
		int res=0,result=0;
		for(vector<int>::iterator iter=nums.begin();iter!=nums.end();++iter)
		{
			res=0;
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
			vector<int> tmp=nums;
			tmp.erase(iter-nums.begin()+tmp.begin());
			res+=maxCoins(tmp);
			if(res>result)
				result=res;
		}
		return result;
    }
};
