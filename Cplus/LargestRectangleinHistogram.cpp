#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		return largestRectangleArea(heights,0,heights.size()-1);
    }

	int largestRectangleArea(vector<int>& heights,int i,int j)
	{
		if(i>j)
			return 0;
		int m=i,tmp=INT_MAX,res=0;
		for(int k=i;k<=j;k++)
		{
			if(tmp>heights[k])
			{
				tmp=heights[k];
				m=k;
			}
		}
		res=heights[m]*(j-i+1);
		return max(res,max(largestRectangleArea(heights,i,m-1),largestRectangleArea(heights,m+1,j)));
	}
};
