#include<vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int> >& matrix) {
		if(matrix.size()<2||matrix[0].size()<2)
			return true;
		int m=matrix.size(),n=matrix[0].size();
		for(int k=0;k<m;k++)
		{
			int i=k,j=0;
			int tmp=matrix[i][j];
			while(i<m&&j<n)
			{
				if(matrix[i][j]!=tmp)
					return false;
				++i;
				++j;
			}
		}
		for(int k=1;k<n;k++)
		{
			int i=0,j=k;
			int tmp=matrix[i][j];
			while(i<m&&j<n)
			{
				if(matrix[i][j]!=tmp)
					return false;
				++i;
				++j;
			}
		}
        return true;
    }
};
