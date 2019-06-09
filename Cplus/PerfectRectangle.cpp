#include<vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int> >& rectangles) {
        int bottom=INT_MAX,left=INT_MAX,top=INT_MIN,right=INT_MIN,area=0,maxarea;
		set<pair<int,int> > s;
		set<pair<int,int> >::iterator iter;
		for(int i=0;i<(int)rectangles.size();i++)
		{
			bottom=min(rectangles[i][0],bottom);
			left=min(rectangles[i][1],left);
			top=max(rectangles[i][2],top);
			right=max(rectangles[i][3],right);
			area+=(rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);

			iter=s.find({rectangles[i][0],rectangles[i][1]});
			if(iter==s.end())
				s.insert({rectangles[i][0],rectangles[i][1]});
			else
				s.erase(iter);

			iter=s.find({rectangles[i][0],rectangles[i][3]});
			if(iter==s.end())
				s.insert({rectangles[i][0],rectangles[i][3]});
			else
				s.erase(iter);

			iter=s.find({rectangles[i][2],rectangles[i][1]});
			if(iter==s.end())
				s.insert({rectangles[i][2],rectangles[i][1]});
			else
				s.erase(iter);

			iter=s.find({rectangles[i][2],rectangles[i][3]});
			if(iter==s.end())
				s.insert({rectangles[i][2],rectangles[i][3]});
			else
				s.erase(iter);
		}
		if(s.size()!=4||s.find({bottom,left})==s.end()||s.find({bottom,right})==s.end()||s.find({top,left})==s.end()||s.find({top,right})==s.end())
			return false;
		maxarea=(top-bottom)*(right-left);
		return maxarea==area;
    }
};
