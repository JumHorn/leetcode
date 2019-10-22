#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
		int N=intervals.size(),index=0,a=intervals[index][0],b=intervals[index][1];
		while(++index<N)
		{
			if(a>=intervals[index][0]&&b<=intervals[index][1])
				continue;
			if(a<=intervals[index][0]&&b>=intervals[index][1])
			{
				a=intervals[index][0];
				b=intervals[index][1];
			}
			else if(a<=intervals[index][0]&&b>=intervals[index][0])
			{
				if(b-intervals[index][0]<1)
					break;
				a=intervals[index][0];
			}
			else if(a<=intervals[index][1]&&b>=intervals[index][1])
			{
				if(intervals[index][1]-a<1)
					break;
				b=intervals[index][1];
			}
			else
				break;
		}
		if(index==N)
			return 2;
		
		if(intervals[index][0]>=a)
		{
			a=b-1;
			b=max(b,intervals[index][0]+1);
		}
		else
		{
			b=a+1;
			a=min(a,intervals[index][1]-1);
		}

		while(++index<N)
		{
			if(intervals[index][0]>=a)
				b=max(b,intervals[index][0]+1);
			else if(intervals[index][1]<=b)
				a=min(a,intervals[index][1]-1);
		}
		return b-a+1;
    }
};

int main()
{
	vector<vector<int>> v=
	{{2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}};
	Solution sol;
	sol.intersectionSizeTwo(v);
	return 0;
}
