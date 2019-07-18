#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int,int> indexmap;
		unordered_multimap<int,int>::iterator iter;
		for(int i=0;i<(int)nums.size();i++)
			indexmap.insert({nums[i],i});
		for(int i=0;i<(int)nums.size();i++)
		{
            iter=indexmap.find(target-nums[i]);
            if(iter!=indexmap.end())
            {
                if(target-nums[i]==nums[i])
                {
                    if(indexmap.count(nums[i])>=2)
                        return {i,iter->second};
                }
                else
                    return {i,iter->second};
            }
		}
		return vector<int>();
    }
};