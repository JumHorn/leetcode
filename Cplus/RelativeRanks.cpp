#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

class SolutionSimply {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
            vector<string> result;
            vector<int> numscopy(nums);
            string strs[]={"Gold Medal","Silver Medal","Bronze Medal"};
            sort(numscopy.begin(),numscopy.end());
            for(int i=0;i<nums.size();i++)result.push_back(to_string(nums.size()-distance(numscopy.begin(),find(numscopy.begin(),numscopy.end(),nums[i]))));           
            for(int i=0;i<min((int)nums.size(),3);i++)result[distance(nums.begin(),find(nums.begin(),nums.end(),numscopy[nums.size()-i-1]))]=strs[i];
            return result;
    }
};

class Solution {
	public:
		vector<string> findRelativeRanks(vector<int>& nums) 
		{
			vector<string> result;
			vector<int> numscopy(nums);
			string strs[]={"Gold Medal","Silver Medal","Bronze Medal"};
			//这里可以使用冒泡排序，实现前三即可
			sort(numscopy.begin(),numscopy.end());
			reverse(numscopy.begin(),numscopy.end());
			for(int i=0;i<nums.size();i++)
			{
				result.push_back(to_string(1+distance(numscopy.begin(),find(numscopy.begin(),numscopy.end(),nums[i]))));
			}
			//调换下面方法
			int length=3;
			if(nums.size()<length)length=nums.size();
			for(int i=0;i<length;i++)
			{
				result[distance(nums.begin(),find(nums.begin(),nums.end(),numscopy[0]))]=strs[i];
			}
			//int i,j,k;
			//i=find(nums.begin(),nums.end(),numscopy[0])-nums.begin();
			//j=find(nums.begin(),nums.end(),numscopy[1])-nums.begin();
			//k=find(nums.begin(),nums.end(),numscopy[2])-nums.begin();
			//i=distance(nums.begin(),find(nums.begin(),nums.end(),numscopy[0]));
			//j=distance(nums.begin(),find(nums.begin(),nums.end(),numscopy[1]));
			//k=distance(nums.begin(),find(nums.begin(),nums.end(),numscopy[2]));
			//result[i]="Gold Medal";
			//result[j]="Silver Medal";
			//result[k]="Bronze Medal";
			return result;
		}
};

int main()
{}
