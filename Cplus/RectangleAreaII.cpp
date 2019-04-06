#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	static const int mode=1000000000+7;
public:
    int rectangleArea(vector<vector<int> >& rectangles) {
		sort(rectangles.begin(),rectangles.end(),*this);
		unsigned long long h=0,y=0,x=0,ylen=0,xlen=0;
		unsigned long long res=0;
		for(int i=0;i<(int)rectangles.size();i++)
			h=max((int)h,rectangles[i][3]);
		while(y<h)
		{
			x=0;
			xlen=0;
			ylen=INT_MAX;
			bool flag=false;
			for(int i=0;i<(int)rectangles.size();i++)
			{
				if(rectangles[i][1]>(int)y)
					ylen=min((int)ylen,rectangles[i][1]);
				if((int)y>=rectangles[i][1]&&(int)y<rectangles[i][3]&&rectangles[i][2]>(int)x)
				{
					flag=true;
					x=max((int)x,rectangles[i][0]);
					ylen=min((int)ylen,rectangles[i][3]);
					xlen+=rectangles[i][2]-x;
					x=rectangles[i][2];
				}
			}
			if(flag)
			{
				res+=xlen*(ylen-y);
				y=ylen;
			}
			else
				y=ylen;
		}
		return res%mode;
    }

	bool operator()(vector<int>& left,vector<int>& right)
	{
		if(left[0]<right[0])
			return true;
		return false;
	}
};
