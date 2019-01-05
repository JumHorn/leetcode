#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int i=0,j=0,k=0;
		for(i=1;i<(int)nums.size();i++)
		{
			if(k==1&&nums[i]==nums[j])
            {
                nums.erase(nums.begin()+i);
                i--;
            }
            else
            {
                if(nums[i]==nums[j])
                    k++;
                else
                {
                    j=i;
                    k=0;
                }
            }
		}
		return nums.size();
    }
};
