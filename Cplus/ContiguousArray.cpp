#include<vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		int res=0;
		for(int i=0;i<nums.size();i++)
		{
			int one=0,zero=0;
			for(int j=i;j<nums.size();j++)
			{
				nums[j]?one++:zero++;
				if(one==zero&&j-i+1>res)
					res=j-i+1;
			}
		}
		return res;
    }
};
