#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
		if(hand.size()%W!=0)
			return false;
		sort(hand.begin(),hand.end());
		int start=0;
		while(start<hand.size())
		{
			int m=hand[start];
			int j=start+1;
			hand[start]=-1;
			for(int i=m+1;i<W+m;i++)
			{
				for(;j<hand.size();j++)
				{
					if(hand[j]==i)
					{
						hand[j]=-1;
						break;
					}
					if(hand[j]>i)
						return false;
				}
				if(j==hand.size())
					return false;
			}
			while(hand[start]==-1)start++;
		}
		return true;
    }
};
