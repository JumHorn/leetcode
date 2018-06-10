#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
	    map<int,int> dic;
		for(int i=0;i<nums.size();i++)
		{
			dic[nums[i]]++;
		}		
		for(int i=0;i<k;i++)
		{
			res.push_back(findmax(dic));
		}
		return res;
    }
	int findmax(map<int,int>& dic)
	{
		int minval=0;
		int res;
		map<int,int>::iterator it;
		for(map<int,int>::iterator iter=dic.begin();iter!=dic.end();iter++)
		{
			if(iter->second>minval)
			{
				minval=iter->second;
				res=iter->first;
				it=iter;
			}
		}
		dic.erase(it);
		return res;
	}
};
