#include <algorithm>
using namespace std;

/*
1D line1 (a,b) line2 (c,d)
if line1 is intersect with line2
c < b && d > a

2D rectangle can be viewd as 1D x axis and 1D y asis
*/

class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		int area1 = (C - A) * (D - B);
		int area2 = (G - E) * (H - F);
		int intersection = 0;
		if (E < C && G > A && F < D && H > B)
			intersection = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
		return area1 + (area2 - intersection); //avoid (area1 + area2) integer overflow
	}
};