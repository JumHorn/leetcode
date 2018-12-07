#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
		int low=1,high=1000000000;
		while(low<high)
		{
			int middle=low+(high-low)/2;
			if(eatAll(piles,middle,H))
				high=middle;
			else
				low=middle+1;
		}
		return low;
    }

	bool eatAll(vector<int>& piles,int k,int H)
	{
		int hour=0;
		for(int i=0;i<piles.size();i++)
			hour+=(piles[i]-1)/k+1;
		return hour<=H;
	}
};
