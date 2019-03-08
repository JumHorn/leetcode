#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
		vector<double> tmp(nums.begin(),nums.end());
		return judgePoint24(tmp);
	}

    bool judgePoint24(vector<double>& nums) {
		if(nums.size()==1&&abs(nums.back()-24)<0.000001)
			return true;
		for(int i=0;i<(int)nums.size();i++)
		{
			for(int j=i+1;j<(int)nums.size();j++)
			{
				vector<double> v;
				for(int k=0;k<(int)nums.size();k++)
				{
					if(k!=i&&k!=j)
						v.push_back(nums[k]);
				}
				double tmp=nums[i]+nums[j];
				v.push_back(tmp);
				if(judgePoint24(v))
					return true;
				v.pop_back();

				tmp=nums[i]*nums[j];
				v.push_back(tmp);
				if(judgePoint24(v))
					return true;
				v.pop_back();

				tmp=nums[i]-nums[j];
				v.push_back(tmp);
				if(judgePoint24(v))
					return true;
				v.pop_back();

				tmp=nums[i]-nums[j];
				v.push_back(-tmp);
				if(judgePoint24(v))
					return true;
				v.pop_back();

				tmp=nums[i]/nums[j];
				v.push_back(tmp);
				if(judgePoint24(v))
					return true;
				v.pop_back();

				tmp=nums[j]/nums[i];
				v.push_back(tmp);
				if(judgePoint24(v))
					return true;
				v.pop_back();
			}
			
		}
		return false;        
    }
};
