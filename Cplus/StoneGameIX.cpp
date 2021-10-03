#include <vector>
using namespace std;

class Solution
{
public:
	bool stoneGameIX(vector<int> &stones)
	{
		vector<int> count(3);
		for (auto n : stones)
			++count[n % 3];
		return win(count[0], count[1], count[2]);
	}

	bool win(int a, int b, int c) // 0 ,1 ,2
	{
		if (a % 2 == 0)
		{
			if (b == 0 || c == 0)
				return false;
		}
		else
		{
			if (abs(b - c) <= 2)
				return false;
		}
		return true;
	}
};