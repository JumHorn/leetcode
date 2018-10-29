#include<vector>
using namespace std;

//for 45 and horizantal symmetry
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<i;j++)
			{
				matrix[i][j]^=matrix[j][i];
				matrix[j][i]^=matrix[i][j];
				matrix[i][j]^=matrix[j][i];
			}
		}
		for(int j=0;j<matrix.size()/2;j++)
		{
			int k=matrix.size()-j-1;
			for(int i=0;i<matrix.size();i++)
			{
				matrix[i][j]^=matrix[i][k];
				matrix[i][k]^=matrix[i][j];
				matrix[i][j]^=matrix[i][k];
			}
		}
    }
};
