#include <unordered_map>
#include <vector>
using namespace std;

/*
longest subarray with at most two different value
algorithm:
slide window
*/

class Solution
{
public:
	int totalFruit(vector<int> &tree)
	{
		unordered_map<int, int> m;
		int i, j;
		for (i = 0, j = 0; j < (int)tree.size(); ++j)
		{
			++m[tree[j]];
			if ((int)m.size() > 2)
			{
				if (--m[tree[i]] == 0)
					m.erase(tree[i]);
				++i;
			}
		}
		return j - i;
	}
};