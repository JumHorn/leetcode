#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
 		sort(piles.begin(),piles.end());
		int index=0;
	    for(int i=piles.size()-2;i>=0;i--)
		{
			if(!eatAll(piles,piles[i],H))
			{
				index=i;
				break;
			}
		}
		for(int i=piles[index];i<=piles[index+1];i++)
		{
			if(eatAll(piles,i,H))
				return i;
		}
		return 0;
    }

	bool eatAll(vector<int>& piles,int k,int H)
	{
		int hour=0,sum=0,i=0;
		while(i<piles.size() && piles[i]<k)
		{
            sum=0;
			while(i<piles.size())
			{
				sum+=piles[i++];
				if(sum>k)
				{
					i--;
					break;
				}
			}
			hour++;
		}
		while(i<piles.size())
		{
			hour+=piles[i]/k+(piles[i]%k?1:0);
		    i++;
		}
		return hour<=H;
	}
};
