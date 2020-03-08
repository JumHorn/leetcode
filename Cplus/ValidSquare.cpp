#include <vector>
using namespace std;

class Solution
{
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
	{
		vector<int> tmp;
		if (isSquare(p1, p2, p3, tmp) && tmp == p4)
			return true;
		if (isSquare(p1, p2, p4, tmp) && tmp == p3)
			return true;
		if (isSquare(p1, p3, p4, tmp) && tmp == p2)
			return true;
		return false;
	}

	bool isSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& out)
	{
		int a = p2[0] - p1[0], b = p2[1] - p1[1], c = p3[0] - p1[0], d = p3[1] - p1[1];
		if (a * c + b * d != 0)
			return false;
		if (a * a + b * b == 0 || a * a + b * b != c * c + d * d)
			return false;
		out = {a + c + p1[0], b + d + p1[1]};
		return true;
	}
};
