#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	static const int mode=1000000000+7;
public:
    int rectangleArea(vector<vector<int> >& rectangles) {
        vector<vector<int> > v(INT_MAX,vector<int>(INT_MAX));
		int h=0,w=0,res=0;
		for(int k=0;k<(int)rectangles.size();k++)
		{
			w=max(w,rectangles[k][2]);
			h=max(h,rectangles[k][3]);
			for(int i=rectangles[k][0];i<rectangles[k][2];i++)
				for(int j=rectangles[k][1];j<rectangles[k][3];j++)
					v[i][j]=1;
		}
		for(int i=0;i<w;i++)
			for(int j=0;j<h;j++)
				res+=v[i][j]%mode;
		return res;
    }
};
