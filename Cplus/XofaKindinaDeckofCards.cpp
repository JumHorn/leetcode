#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool hasGroupsSizeX(vector<int> &deck)
	{
		unordered_map<int, int> m;
		for (auto d : deck)
			++m[d];
		int count = m.begin()->second;
		for (auto &n : m)
		{
			count = gcd(count, n.second);
			if (count < 2)
				return false;
		}
		return true;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};