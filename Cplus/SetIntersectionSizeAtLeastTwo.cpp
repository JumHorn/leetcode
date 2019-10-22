#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end(),*this);
		int N=intervals.size(),index=N-1,a=intervals[index][0],b=a+1,res=2;
		while(--index>=0)
		{
			if(intervals[index][1]<a)
			{
				a=intervals[index][0];
				b=a+1;
				res+=2;
			}
			else if(intervals[index][1]==a)
			{
                b=a;
				a=intervals[index][0];
				res+=1;
			}
			else
			{
				if(intervals[index][1]<b)
				{
					b=a;
					a=intervals[index][0];
					res+=1;
				}
			}
		}
		return res;
    }

	bool operator()(vector<int>& lhs,vector<int>& rhs)
	{
		if(lhs[0]!=rhs[0])
			return lhs[0]<rhs[0];
		return lhs[1]>rhs[1];
	}
};

