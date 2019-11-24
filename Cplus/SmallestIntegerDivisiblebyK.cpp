#include <unordered_set>
using namespace std;

class Solution
{
public:
	int smallestRepunitDivByK(int K)
	{
		unordered_set<int> m;
		int d = 1, r = 0;
		while (true)
		{
			d %= K;
			if (d == 0)
				return m.size() + 1;
			if (m.find(d) != m.end())
				break;
			m.insert(d);
			d *= 10;
			d += 1;
		}
		return -1;
	}
};