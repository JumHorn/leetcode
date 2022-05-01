#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumCardPickup(vector<int> &cards)
	{
		int N = cards.size(), res = N + 1;
		unordered_map<int, int> m; //{value,index}
		for (int i = 0; i < N; ++i)
		{
			auto it = m.find(cards[i]);
			if (it != m.end())
				res = min(res, i - it->second + 1);
			m[cards[i]] = i;
		}
		if (res > N)
			return -1;
		return res;
	}
};