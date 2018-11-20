#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n,vector<int>(n));
		int l,r,t,b,num=0;
		l=t=0;
		r=b=n;
		while(true)
		{
		    for(int i=l;i<r;i++)//left to right
				res[t][i]=++num;	
			t++;
		    for(int i=t;i<b;i++)//top to bottom
				res[i][r-1]=++num;	
			r--;
		    for(int i=r-1;i>=l;i--)//right to left
				res[b-1][i]=++num;	
			b--;
		    for(int i=b-1;i>=t;i--)//bottom to top
				res[i][l]=++num;
			l++;
			if(r-l<=1)
				break;
		}
		return res;
    }
};
