#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
		if(matrix.empty())
			return false;
		int len=matrix[0].size();
        for(int i=0;i<(int)matrix.size();i++)
			for(int j=0;j<len;j++)
			{
				if(matrix[i][j]==target)
					return true;
				else if(target<matrix[i][j])
				{
					len=j;
					break;
				}
			}
		return false;
    }
};
