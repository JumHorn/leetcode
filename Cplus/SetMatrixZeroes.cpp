#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
		bool row=false,column=false;
		for(int i=0;i<(int)matrix.size();i++)
			if(matrix[i][0]==0)
			{
				row=true;
				break;
			}
		for(int j=0;j<(int)matrix[0].size();j++)
			if(matrix[0][j]==0)
			{
				column=true;
				break;
			}
        for(int i=0;i<(int)matrix.size();i++)
			for(int j=0;j<(int)matrix[0].size();j++)
				if(matrix[i][j]==0)
				{
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
		for(int i=1;i<(int)matrix.size();i++)
		{
			if(matrix[i][0]==0)
				for(int j=1;j<(int)matrix[0].size();j++)
					matrix[i][j]=0;
		}
		for(int j=1;j<(int)matrix[0].size();j++)
		{
			if(matrix[0][j]==0)
				for(int i=1;i<(int)matrix.size();i++)
					matrix[i][j]=0;
		}
		if(row)
			for(int i=0;i<(int)matrix.size();i++)
				matrix[i][0]=0;
		if(column)
			for(int j=0;j<(int)matrix[0].size();j++)
				matrix[0][j]=0;
    }
};
