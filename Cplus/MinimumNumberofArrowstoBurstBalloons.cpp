#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int> >& points) {
		if(points.empty())
			return 0;
		ascending(points);
       	return countArrow(points);
    }

	int countArrow(vector<pair<int,int> >& points)
	{
        if(points.size()<2)
			return points.size();
		int i=0,minindex=0,minsecond=INT_MAX;
		for(i=0;i<points.size();i++)
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
		vector<pair<int,int> > tmp(points.begin()+j,points.end());
		return 1+countArrow(tmp);
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
					swap(points[j],points[j-1]);
					s=false;
				}
			}
			if(s)
				break;
		}
	}
};
