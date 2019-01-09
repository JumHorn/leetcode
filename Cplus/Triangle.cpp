#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
		if(triangle.empty())
			return 0;
        if(triangle.size()==1)
            return triangle[0][0];
        vector<int> tmp(triangle.size(),INT_MAX);
		for(int i=1;i<(int)triangle.size();i++)
		{
			for(int j=0;j<(int)triangle[i-1].size();j++)
			{
				tmp[j]=min(triangle[i-1][j]+triangle[i][j],tmp[j]);
				tmp[j+1]=min(triangle[i-1][j]+triangle[i][j+1],tmp[j+1]);
			}
			for(int k=0;k<(int)triangle[i].size();k++)
            {
				triangle[i][k]=tmp[k];
                tmp[k]=INT_MAX;
            }
		}
		return *min_element(triangle.back().begin(),triangle.back().end());
    }
};
