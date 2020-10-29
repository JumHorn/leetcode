#include <vector>
using namespace std;

class Solution
{
public:
	bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
	{
		return !isEmptyRectangle(rec1) &&
			   !isEmptyRectangle(rec2) &&
			   lineOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) &&
			   lineOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
	}

	//two range [x1,x2] [x3,x4] overlap
	bool lineOverlap(int x1, int x2, int x3, int x4)
	{
		return x1 < x4 && x2 > x3;
	}

	bool isEmptyRectangle(vector<int> &rect)
	{
		return rect[0] == rect[2] || rect[1] == rect[3];
	}
};