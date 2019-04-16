#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int,int> head,tail;
		unordered_set<int> visited;
		int res=1;
		for(int i=0;i<(int)nums.size();i++)
		{
			if(visited.find(nums[i])!=visited.end())
				continue;
			visited.insert(nums[i]);
			if(head.find(nums[i])==head.end()&&tail.find(nums[i])==tail.end())
			{
				head[nums[i]-1]=nums[i]+1;
				tail[nums[i]+1]=nums[i]-1;
			}
			else if(head.find(nums[i])!=head.end()&&tail.find(nums[i])==tail.end())
			{
				head[nums[i]-1]=head[nums[i]];
				tail[head[nums[i]]]=nums[i]-1;
				res=max(res,head[nums[i]]-nums[i]);
			}
			else if(head.find(nums[i])==head.end()&&tail.find(nums[i])!=tail.end())
			{
				tail[nums[i]+1]=tail[nums[i]];
				head[tail[nums[i]]]=nums[i]+1;
				res=max(res,nums[i]-tail[nums[i]]);
			}
			else
			{
				head[tail[nums[i]]]=head[nums[i]];
				tail[head[nums[i]]]=tail[nums[i]];
				res=max(res,head[nums[i]]-tail[nums[i]]-1);
			}
		}
		return res;
    }
};
