#include <stdbool.h>

bool isSquare(int* p1, int* p2, int* p3, int* p4)
{
	int a = p2[0] - p1[0], b = p2[1] - p1[1], c = p3[0] - p1[0], d = p3[1] - p1[1];
	if (a * a + b * b == 0 || a * c + b * d != 0 || a * a + b * b != c * c + d * d)
		return false;
	return p4[0] == a + c + p1[0] && p4[1] == b + d + p1[1];
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size)
{
	return isSquare(p1, p2, p3, p4) || isSquare(p1, p2, p4, p3) || isSquare(p1, p3, p4, p2);
}
