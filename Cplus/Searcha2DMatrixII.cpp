#include<vector>
using namespace std;

/*
search from top right
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
		if(matrix.empty())
			return false;
		int row=0,column=matrix[0].size()-1;
		while(row<(int)matrix.size()&&column>=0)
		{
			if(matrix[row][column]==target)
				return true;
			else if(target>matrix[row][column])
				row++;
			else
				column--;
		}
		return false;
    }
};
