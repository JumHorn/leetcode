#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
		int N=nums.size();
		vector<int> res(nums);
		sort(res.begin(),res.end());
		int i=N/2-((N^1)&1),m=i,j=N-1,k=0;
		while(i>=0)
		{
			nums[k++]=res[i--];
            if(j>m)
			    nums[k++]=res[j--];
		}
    }
};
