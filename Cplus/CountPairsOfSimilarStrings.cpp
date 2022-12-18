#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int similarPairs(vector<string> &words)
	{
		int res = 0;
		unordered_map<int, int> m; //{mask,count}
		for (auto &w : words)
		{
			int mask = 0;
			for (auto c : w)
				mask |= 1 << (c - 'a');
			res += m[mask]++;
		}
		return res;
	}
};