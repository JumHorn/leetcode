#include<vector>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
		return canCross(stones,0,0);        
    }

	bool canCross(vector<int>& stones,int current,int skip)
	{
		if(current==(int)stones.size()-1)
			return true;
		int k=skip+1,i,j;
		for(i=current+1;i<(int)stones.size();i++)
		{
			if(k+stones[current]==stones[i]&&canCross(stones,i,k))
				return true;
			if(stones[i]>k+stones[current])
				break;
		}
		k--;
		if(k>0)
		{
			for(j=i-1;j>current;j--)
			{
				if(k+stones[current]==stones[j]&&canCross(stones,j,k))
					return true;
				if(stones[j]<k+stones[current])
					break;
			}
		}
		k--;
		if(k>0)
		{
			for(;j>current;j--)
			{
				if(k+stones[current]==stones[j]&&canCross(stones,j,k))
					return true;
				if(stones[j]<k+stones[current])
					break;
			}
		}
		return false;
	}
};