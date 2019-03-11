#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
		int res=0;
		int index=0;
		if(seats[0]==0)
		{
			while(index<(int)seats.size()&&seats[index]==0)
				index++;
			res=index;
		}
		while(index<(int)seats.size())
		{
			if(seats[index]==0)
			{
				int tmp=index;
				while(index<(int)seats.size()&&seats[index]==0)
					index++;
				tmp=index-tmp;
				res=max(res,tmp/2+tmp%2);
			}
			else
				index++;
		}		
		--index;
		if(seats[index]==0)
		{
			while(index>=0&&seats[index]==0)
				--index;
			res=max(res,(int)seats.size()-index-1);
		}
		return res;
    }
};
