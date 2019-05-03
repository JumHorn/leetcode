#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty())
            return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
		if(sum%4!=0)
			return false;
		int matchlen=sum/4;
		vector<int> square(4);
		square[0]=nums.front();
		return makesquare(nums,matchlen,square,1);
    }

	bool makesquare(vector<int>& nums,int matchlen,vector<int>& square,int start)
	{
		if(start==(int)nums.size())
			return square[0]==matchlen&&square[1]==matchlen&&square[2]==matchlen&&square[3]==matchlen;
		for(int j=0;j<4;j++)
		{
			if(square[j]+nums[start]<=matchlen)
			{
				square[j]+=nums[start];
				if(makesquare(nums,matchlen,square,start+1))
					return true;
				square[j]-=nums[start];
			}
		}
		return false;
	}
};
