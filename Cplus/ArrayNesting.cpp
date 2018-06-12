#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		int unmarked=nums.size();
		if(unmarked==0)
		{
			return 0;
		}
		int *mark = new int[unmarked];
		memset(mark,0,sizeof(int)*unmarked);
		int marknum=1,maxmarknum=0,markflag=1;
		map<int,int> hash;
		//initialize
		mark[0]=markflag;
		unmarked--;
		int tmp=nums[0];
		while(unmarked!=0)
		{
			if(mark[tmp]==markflag)
			{
				hash[markflag]=marknum;
				if(maxmarknum<marknum)
					maxmarknum=marknum;
				//remark
				markflag++;
				if(unmarked==0)
					return maxmarknum;
				marknum=1;
				unmarked--;
				for(int i=0;i<nums.size();i++)
				{
					if(mark[i]==0)
					{
						mark[i]=markflag;
						tmp=nums[i];
						break;
					}
				}
			}
			else if(mark[tmp]==0)
			{
				mark[tmp]=markflag;
				marknum++;
				unmarked--;
				tmp=nums[tmp];
			}
		}	
		return maxmarknum>marknum?maxmarknum:marknum;		
    }
};
