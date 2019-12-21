#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestWPI(vector<int>& hours)
	{
		hours[0] = hours[0] > 8 ? 1 : -1;
		for (int i = 1; i < (int)hours.size(); i++)
		{
			hours[i] = hours[i] > 8 ? 1 : -1;
			hours[i] += hours[i - 1];
		}
		if (hours[hours.size() - 1] > 0)
			return hours.size();
		unordered_map<int, int> m;
		m[0] = -1;
		int res = 0;
		for (int i = 0; i < (int)hours.size(); i++)
		{
			if (m.find(hours[i] - 1) != m.end())
				res = max(res, i - m[hours[i] - 1]);
			if (m.find(hours[i]) == m.end())
				m[hours[i]] = i;
		}
		return res;
	}
};

