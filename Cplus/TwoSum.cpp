#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexmap;
		unordered_map<int,int>::iterator iter;
		for(int i=0;i<(int)nums.size();i++)
		{
            iter=indexmap.find(target-nums[i]);
            if(iter!=indexmap.end())
                return {iter->second,i};
            indexmap.insert({nums[i],i});
		}
		return vector<int>();
    }
};