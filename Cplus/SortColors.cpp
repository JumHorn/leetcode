#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int flag01=0,flag12=nums.size()-1;
		while(flag01<flag12&&nums[flag01]==0)
			flag01++;
		while(flag12>flag01&&nums[flag12]==2)
			flag12--;
		for(int i=flag01;i<=flag12;i++)
		{
			if(nums[i]==2)
			{
				nums[i--]=nums[flag12];
				nums[flag12--]=2;
			}
			else if(nums[i]==0)
			{
				nums[flag01]=0;
                if(flag01++!=i)
				    nums[i]=1;
			}
		}
    }
};
