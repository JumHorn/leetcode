#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isNStraightHand(vector<int> &hand, int W)
	{
		int N = hand.size();
		if (N % W != 0)
			return false;
		map<int, int> m;
		for (auto n : hand)
			++m[n];
		while (!m.empty())
		{
			int start = m.begin()->first, count = m.begin()->second;
			for (int i = 0; i < W; ++i)
			{
				m[start + i] -= count;
				if (m[start + i] < 0)
					return false;
				if (m[start + i] == 0)
					m.erase(start + i);
			}
		}
		return true;
	}
};