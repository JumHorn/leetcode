#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
		map<int,int> bricks;
		int height=0;
	    for(vector<vector<int> >::iterator iter=wall.begin();iter!=wall.end();iter++)
		{
			addOne(bricks);
			height++;
			int len=0;
			for(vector<int>::iterator it=iter->begin();it!=iter->end()-1;iter++)
			{
				len+=*it;
				if(bricks.count(len)==0)
				{
					bricks[len]=height-1;
				}
				else
				{
					bricks[len]--;
				}
			}
		}
		//find min
		int res=INT_MAX;
		for(map<int,int>::iterator iter=bricks.begin();iter!=bricks.end();iter++)
		{
			if(iter->second<res)
				res=iter->second;
		}
		return res;
    }
	
	void addOne(map<int,int>& bricks)
	{
		for(map<int,int>::iterator iter=bricks.begin();iter!=bricks.end();iter++)
		{
			iter->second++;
		}
	}
};
