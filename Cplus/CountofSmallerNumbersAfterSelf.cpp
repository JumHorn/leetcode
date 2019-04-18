#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
		vector<int> res(nums.size());
		for(int i=(int)nums.size()-2;i>=0;i--)
		{
			for(int j=i+1;j<(int)nums.size();j++)
				if(nums[i]>nums[j])
				{
					if(res[j]==(int)nums.size()-j-1)
					{
						res[i]+=res[j]+1;
						break;
					}
					++res[i];
				}
		}
		return res;		
    }
};
