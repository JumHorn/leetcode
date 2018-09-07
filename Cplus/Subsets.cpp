#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
		for(int i=0;i<=nums.size();i++)
		{
			vector<int> instance(i);
			combine(res,nums,instance,0,0);
		}
		return res;
    }

	void combine(vector<vector<int> >& res,vector<int>& nums,vector<int>& instance,int l,int k)
	{
		if(l==instance.size())
		{
			res.push_back(instance);
			return;
		}
		for(int i=k;i<nums.size();i++)
		{
			instance[l]=nums[i];
			combine(res,nums,instance,l+1,i+1);
		}
	}
};

//a greater solution
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector< vector<int>>res;
        if(nums.size()==0)
            return res;

        unsigned int pow_set_size = pow(2, nums.size());
        int counter, j;


        for(counter = 0; counter < pow_set_size; counter++)
        {
            vector<int>r;
          for(j = 0; j < nums.size(); j++)
           {

              if(counter & (1<<j))
                r.push_back(nums[j]);
           }
           res.push_back(r);
        }
        return res;
    }
};

*/
