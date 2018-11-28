#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		int res=0,total=0;
		map<int,int> hash;
        hash[0]=-1;
		for(int i=0;i<nums.size();i++)
		{
			nums[i]?total++:total--;
			if(hash.count(total)!=0)
				res=max(res,i-hash[total]);
			else
				hash[total]=i;
		}
		return res;
    }
};
