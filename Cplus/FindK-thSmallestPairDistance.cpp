#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
		int high=nums.back()-nums.front(),low=0;
		while(low<high)
		{
			int mid=(high-low)/2+low,count=0,i=0,j=0;
			for(;i<(int)nums.size();i++)
			{
				while(j<(int)nums.size()&&nums[j]-nums[i]<=mid)
					j++;
				count+=j-i-1;
			}
            if(count<k)
                low=mid+1;
            else
                high=mid;
		}
		return low;
    }
};
