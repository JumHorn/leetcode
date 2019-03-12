#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<vector<int> > dp;
		vector<int> res(3);
		vector<int> v(4);//v[0] index v[1] min v[2] max v[3] sum
		v[0]=0;
		v[1]=INT_MAX;
		v[2]=INT_MIN;
		v[3]=0;
		for(int i=0;i<k;i++)
		{
			v[3]+=nums[i];
			if(nums[i]>v[2])
				v[2]=nums[i];
			if(nums[i]<v[1])
				v[1]=nums[i];
		}		

		//slide window
		dp.push_back(v);
		for(int i=1;i<=(int)nums.size()-k;i++)
		{
			v[0]=i;
			v[3]=v[3]-nums[i-1]+nums[i+k-1];
			if(nums[i-1]==v[1])
				v[1]=*min_element(nums.begin()+i,nums.begin()+i+k);
			else if(nums[i-1]==v[2])
				v[2]=*max_element(nums.begin()+i,nums.begin()+i+k);

			if(nums[i+k-1]>v[2])
				v[2]=nums[i+k-1];
			else if(nums[i+k-1]<v[1])
				v[1]=nums[i+k-1];
			dp.push_back(v);
		}
		
		int m=INT_MIN;
		for(int i=0;i<(int)dp.size()-2;i++)
		{
			for(int j=i+1;j<(int)dp.size()-1;j++)
			{
				if(overlap(dp[i],dp[j]))
					continue;
				for(int k=j+1;k<(int)dp.size();k++)
				{
					if(overlap(dp[i],dp[k])||overlap(dp[j],dp[k]))
						continue;
					if(dp[i][3]+dp[j][3]+dp[k][3]>m)
					{
						m=dp[i][3]+dp[j][3]+dp[k][3];
						res[0]=i;
						res[1]=j;
						res[2]=k;
					}
				}
			}
		}

		return res;
    }

	bool overlap(vector<int>& v1,vector<int>& v2)
	{
		return (v1[1]<v2[2]&&v1[2]>v2[1])||(v2[1]<v1[2]&&v2[2]>v1[1]);
	}
};
