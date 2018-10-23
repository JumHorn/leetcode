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
			for(vector<int>::iterator it=iter->begin();it!=iter->end()-1;it++)
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
		if(bricks.size()==0)
		{
			res=wall.size();
		}
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

//int leastBricks(vector<vector<int>>& wall) {
//    unordered_map<int, int> edges;
//    auto min_bricks = wall.size();
//    for (auto row : wall)
//        for (auto i = 0, width = 0; i < row.size() - 1; ++i) // skip last brick
//            min_bricks = min(min_bricks, wall.size() - (++edges[width += row[i]]));
//    return min_bricks;
//}
