#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numMovesStones(int a, int b, int c)
	{
		//a<b<c
		if (a > c)
			swap(a, c);
		if (a > b)
			swap(a, b);
		if (b > c)
			swap(b, c);

		if (c - a == 2)
			return {0, 0};
		return {min(b - a, c - b) <= 2 ? 1 : 2, c - a - 2};
	}
};