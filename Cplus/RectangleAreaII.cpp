#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	static const int mode=1000000000+7;
public:
    int rectangleArea(vector<vector<int> >& rectangles) {
		sort(rectangles.begin(),rectangles.end(),*this);
		int h=0,y=-1,x=0;
		unsigned long long res=0;
		for(int i=0;i<(int)rectangles.size();i++)
			h=max(h,rectangles[i][3]);
		while(++y<h)
		{
			x=0;
			for(int i=0;i<(int)rectangles.size();i++)
			{
				if(y>=rectangles[i][1]&&y<rectangles[i][3]&&rectangles[i][2]>x)
				{
					x=max(x,rectangles[i][0]);
					res+=rectangles[i][2]-x;
					x=rectangles[i][2];
				}
			}
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
