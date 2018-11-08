#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int> >& points) {
		if(points.empty())
			return 0;
		ascending(points);
       	return countArrow(points,0);
    }

	int countArrow(vector<pair<int,int> >& points,int start)
	{
        if(points.size()-start<2)
			return points.size()-start;
		int i=0,minindex=0,minsecond=INT_MAX;
		for(i=start;i<points.size();i++)
		{
			if(points[i].second<minsecond)
			{
				minsecond=points[i].second;
				minindex=i;
			}
		}
		int j=0;
		for(j=minindex+1;j<points.size();j++)
		{
			if(points[j].first>minsecond)
				break;
		}
		return 1+countArrow(points,j);
	}

	void ascending(vector<pair<int,int> >& points)
	{
		for(int i=0;i<points.size()-1;i++)
		{
			bool s=true;
			for(int j=points.size()-1;j>i;j--)
			{
				if(points[j].first<points[j-1].first)
				{
					int tmp=points[j].first;
                    points[j].first=points[j-1].first;
                    points[j-1].first=tmp;
					tmp=points[j].second;
                    points[j].second=points[j-1].second;
                    points[j-1].second=tmp;
					s=false;
				}
			}
			if(s)
				break;
		}
	}
};
