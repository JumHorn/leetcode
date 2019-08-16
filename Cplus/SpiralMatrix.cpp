#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return vector<int>();
		int l=0,r=matrix[0].size(),b=0,t=matrix.size(),x=0,y=0,i=0;//left right bottom top
		vector<int> res(r*t);
		while(l<r&&b<t)
		{
			while(y<r)
				res[i++]=matrix[x][y++];
            if(l>=r||b>=t)
                break;
			--y;
			++x;
			++b;
			while(x<t)
				res[i++]=matrix[x++][y];
            if(l>=r||b>=t)
                break;
			--x;
			--y;
			--r;
			while(y>=l)
				res[i++]=matrix[x][y--];
            if(l>=r||b>=t)
                break;
			++y;
			--x;
			--t;
			while(x>=b)
				res[i++]=matrix[x--][y];
            if(l>=r||b>=t)
                break;
			++y;
			++x;
			++l;
		}
		return res;
    }
};