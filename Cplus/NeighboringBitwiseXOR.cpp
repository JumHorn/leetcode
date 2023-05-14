#include <vector>
using namespace std;

class Solution
{
public:
	bool doesValidArrayExist(vector<int> &derived)
	{
		int x = 0;
		for (auto n : derived)
			x ^= n;
		return x == 0;
	}
};