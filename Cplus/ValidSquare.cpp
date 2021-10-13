#include <vector>
using namespace std;

class Solution
{
public:
	bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
	{
		return isSquare(p1, p2, p3, p4) || isSquare(p1, p2, p4, p3) || isSquare(p1, p3, p4, p2);
	}

	// p1 p4 diagonal
	bool isSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
	{
		int a = p2[0] - p1[0], b = p2[1] - p1[1], c = p3[0] - p1[0], d = p3[1] - p1[1];
		if (a * a + b * b == 0 || a * c + b * d != 0 || a * a + b * b != c * c + d * d)
			return false;
		return p4[0] == a + c + p1[0] && p4[1] == b + d + p1[1];
	}
};