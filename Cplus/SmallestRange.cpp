#include<vector>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<int> res(2);
		vector<int> index(nums.size());
		int maxindex,minindex,range=INT_MAX;
		while(correctIndex(index,nums))
		{
			maxindex=getMax(index,nums);
			minindex=getMin(index,nums);
			int tmp=nums[maxindex][index[maxindex]]-nums[minindex][index[minindex]];
			if(tmp<range)
			{
				res[0]=nums[minindex][index[minindex]];
				res[1]=nums[maxindex][index[maxindex]];
				range=tmp;
			}
			++index[minindex];
		}
		return res;
    }
	
	int getMax(vector<int>& index,vector<vector<int>>& nums)
	{
		int tmp=INT_MIN,res=index[0];
		for(int i=0;i<(int)index.size();i++)
		{
			if(nums[i][index[i]]>tmp)
			{
				tmp=nums[i][index[i]];
				res=i;
			}
		}
		return res;
	}

	int getMin(vector<int>& index,vector<vector<int>>& nums)
	{
		int tmp=INT_MAX,res=index[0];
		for(int i=0;i<(int)index.size();i++)
		{
			if(nums[i][index[i]]<tmp)
			{
				tmp=nums[i][index[i]];
				res=i;
			}
		}
		return res;
	}

	bool correctIndex(vector<int>& index,vector<vector<int>>& nums)
	{
		for(int i=0;i<(int)index.size();i++)
			if(index[i]>=(int)nums[i].size())
				return false;
		return true;
	}
};
