#include<vector>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
		int XOR=0;
		for(int i=0;i<(int)nums.size();i++)
			XOR^=nums[i];		
		return xorGame(nums,XOR);
    }

	bool xorGame(vector<int>& nums,int XOR)
	{
		if(XOR==0)
			return true;
        bool res=true;
		for(int i=0;i<(int)nums.size();i++)
		{
			if(nums[i]!=-1)
			{
				XOR^=nums[i];
				int tmp=nums[i];
				nums[i]=-1;
				if(XOR!=0&&xorGame(nums,XOR))
					res=false;
				nums[i]=tmp;
				XOR^=nums[i];
			}
		}
		return res;
	}
};

int main()
{
    vector<int> v={1,1,2,3,4};
    Solution sol;
    sol.xorGame(v);
    return 0;
}