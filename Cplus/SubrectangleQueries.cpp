#include <vector>
using namespace std;

class SubrectangleQueries
{
public:
	SubrectangleQueries(vector<vector<int>> &rectangle) : rect(rectangle)
	{
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
	{
		updatedRec.push_back({row1, col1, row2, col2, newValue});
	}

	int getValue(int row, int col)
	{
		for (int i = (int)updatedRec.size() - 1; i >= 0; --i)
		{
			if (row >= updatedRec[i][0] && row <= updatedRec[i][2] &&
				col >= updatedRec[i][1] && col <= updatedRec[i][3])
				return updatedRec[i][4];
		}
		return rect[row][col];
	}

private:
	vector<vector<int>> &rect;
	vector<vector<int>> updatedRec;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */